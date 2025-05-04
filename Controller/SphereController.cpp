#include "SphereController.h"

SphereController::SphereController(SphereModel* model, SphereView* view)
    : model(model), view(view),
      mapper(vtkSmartPointer<vtkPolyDataMapper>::New()),
      actor(vtkSmartPointer<vtkActor>::New()),
      renderer(vtkSmartPointer<vtkRenderer>::New()) {

    mapper->SetInputConnection(model->getSphereSource()->GetOutputPort());
    actor->SetMapper(mapper);

    renderer->AddActor(actor);
    renderer->SetBackground(0.2, 0.3, 0.4);

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    view->getVTKWidget()->setRenderWindow(renderWindow);
    view->getVTKWidget()->renderWindow()->AddRenderer(renderer);

    QObject::connect(view->getSlider(), &QSlider::valueChanged,
                     this, &SphereController::onRadiusChanged);

    view->getVTKWidget()->renderWindow()->Render();
}

void SphereController::onRadiusChanged(int value) {
    model->setRadius(static_cast<double>(value));
    view->getVTKWidget()->renderWindow()->Render();
}
