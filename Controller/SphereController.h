#pragma once
#include "Model/SphereModel.h"
#include "View/SphereView.h"
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkPolyDataMapper.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPointData.h>
#include <vtkSphereSource.h>
#include <vtkDoubleArray.h>
#include <vtkPolyData.h>
#include <cmath>
#include <cstdlib>
#include <random>

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
    /**
 * Deform the sphere source using a random amplitude and modes and render it in
 * the window
 *
 * @param sphere the original sphere source
 * @param mapper the mapper for the scene
 * @param window the window to render to
 * @param randEng the random number generator engine
 */
    void onRandButtonClicked(vtkSphereSource* sphere, vtkDataSetMapper* mapper,
           vtkGenericOpenGLRenderWindow* window, std::mt19937& randEng);

private:
    SphereModel* model;
    SphereView* view;
    std::mt19937 randEng;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkDataSetMapper> mapper;
};