#pragma once
#include "Model/SphereModel.h"
#include "View/SphereView.h"
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkPolyDataMapper.h>
#include <QObject>

/**
 * @class SphereController
 * @brief The SphereController class handles interaction between the model and the view.
 * 
 * This class listens for changes in the slider and updates the model and view accordingly.
 */
class SphereController : public QObject {
    Q_OBJECT
public:
    SphereController(SphereModel* model, SphereView* view);

private slots:
    void onRadiusChanged(int value);

private:
    SphereModel* model;
    SphereView* view;

    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkPolyDataMapper> mapper;
};
