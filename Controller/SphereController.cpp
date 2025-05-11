#include "SphereController.h"


// SphereSettings sphere_settings;
// QtSettings qt_settings;

SphereController::SphereController(SphereModel* model, SphereView* view)
    : model(model), view(view), randEng(model->getSphereSettings().rand_seed),
      mapper(vtkSmartPointer<vtkDataSetMapper>::New()),
      actor(vtkSmartPointer<vtkActor>::New()),
      renderer(vtkSmartPointer<vtkRenderer>::New()),
      renderWindow( vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()){

    mapper->SetInputConnection(model->getSphereSource()->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);
    renderer->SetBackground(0.2, 0.3, 0.4);
    renderWindow->AddRenderer(renderer);

    view->getQVNativeWidget()->setRenderWindow(renderWindow);

// Initialize first visualization
    onRandButtonClicked();

// Connect the rand button to random visualization generator
    QObject::connect(view->getRandButton(), &QPushButton::released, this,
        &SphereController::onRandButtonClicked);

    QObject::connect(view->getSlider(), &QSlider::valueChanged, this,
        &SphereController::onSliderValueChanged);

}

vtkSmartPointer<vtkPolyData> SphereController::getDeformedSphere() const {

    double randAmp = 0.2 + ((model->getSphereSettings().current_rand % 1000) / 1000.0) * 0.2;
    double randThetaFreq = 1.0 + (model->getSphereSettings().current_rand % 9);
    double randPhiFreq = 1.0 + (model->getSphereSettings().current_rand % 9);

    // Extract and prepare data.
    model->getSphereSource()->Update();
    vtkSmartPointer<vtkPolyData> newSphere = vtkSmartPointer<vtkPolyData>::New();
    newSphere.TakeReference(model->getSphereSource()->GetOutput()->NewInstance());
    newSphere->DeepCopy(model->getSphereSource()->GetOutput());
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
    return newSphere;
}

void SphereController::onRandButtonClicked() {
    // Generate randomness.
    model->setCurrentRand(randEng());

    // Reconfigure the pipeline to take the new deformed sphere.
    mapper->SetInputDataObject(getDeformedSphere());
    mapper->SetScalarModeToUsePointData();
    mapper->ColorByArrayComponent("Height", 0);
    renderWindow->Render();
}

void SphereController::onSliderValueChanged(int value) {
    model->setRadius(value/10.0);
    mapper->SetInputDataObject(getDeformedSphere());
    mapper->Update();
    renderWindow->Render();
}

SphereModel* SphereController::getModel() const {
    return model;
}

SphereView* SphereController::getView() const {
    return view;
}
