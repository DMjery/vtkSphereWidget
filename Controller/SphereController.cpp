#include "SphereController.h"

SphereController::SphereController(SphereModel* model, SphereView* view)
    : model(model), view(view), randEng(0),
      mapper(vtkSmartPointer<vtkDataSetMapper>::New()),
      actor(vtkSmartPointer<vtkActor>::New()),
      renderer(vtkSmartPointer<vtkRenderer>::New()) {

    mapper->SetInputConnection(model->getSphereSource()->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);
    renderer->SetBackground(0.2, 0.3, 0.4);

// Connect vtkrender -> vtkgenericrendwin -> qvtkopengl
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow =
    vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    view->getQVNativeWidget()->setRenderWindow(renderWindow);

// Initialize first visualization
    onRandButtonClicked(model->getSphereSource(), mapper, renderWindow, randEng);

// Connect the rand button to random visualization generator
    QObject::connect(view->getRandButton(), &QPushButton::released, this,
                     [=]() {
                         this->onRandButtonClicked(
                         model->getSphereSource(), this->mapper,
                         renderWindow, randEng);
                     });

    view->getQVNativeWidget()->renderWindow()->Render();
}

void SphereController::onRandButtonClicked(vtkSphereSource* sphere, vtkDataSetMapper* mapper,
           vtkGenericOpenGLRenderWindow* window, std::mt19937& randEng) {
    // Generate randomness.
    double randAmp = 0.2 + ((randEng() % 1000) / 1000.0) * 0.2;
    double randThetaFreq = 1.0 + (randEng() % 9);
    double randPhiFreq = 1.0 + (randEng() % 9);

    // Extract and prepare data.
    sphere->Update();
    vtkSmartPointer<vtkPolyData> newSphere = vtkSmartPointer<vtkPolyData>::New();
    newSphere.TakeReference(sphere->GetOutput()->NewInstance());
    newSphere->DeepCopy(sphere->GetOutput());
    vtkNew<vtkDoubleArray> height;
    height->SetName("Height");
    height->SetNumberOfComponents(1);
    height->SetNumberOfTuples(newSphere->GetNumberOfPoints());
    newSphere->GetPointData()->AddArray(height);

    // Deform the sphere.
    for (int iP = 0; iP < newSphere->GetNumberOfPoints(); iP++)
    {
        double pt[3] = {0.0};
        newSphere->GetPoint(iP, pt);
        double theta = std::atan2(pt[1], pt[0]);
        double phi =
            std::atan2(pt[2], std::sqrt(std::pow(pt[0], 2) + std::pow(pt[1], 2)));
        double thisAmp =
            randAmp * std::cos(randThetaFreq * theta) * std::sin(randPhiFreq * phi);
        height->SetValue(iP, thisAmp);
        pt[0] += thisAmp * std::cos(theta) * std::cos(phi);
        pt[1] += thisAmp * std::sin(theta) * std::cos(phi);
        pt[2] += thisAmp * std::sin(phi);
        newSphere->GetPoints()->SetPoint(iP, pt);
    }

    newSphere->GetPointData()->SetScalars(height);

    // Reconfigure the pipeline to take the new deformed sphere.
    mapper->SetInputDataObject(newSphere);
    mapper->SetScalarModeToUsePointData();
    mapper->ColorByArrayComponent("Height", 0);
    window->Render();
}