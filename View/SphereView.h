#pragma once
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QVTKOpenGLNativeWidget.h>

/**
 * @class SphereView
 * @brief The SphereView class represents the user interface.
 * 
 * This class is responsible for displaying the sphere widget and adjusting the radius using a slider.
 */
class SphereView : public QWidget {
    Q_OBJECT
public:
    SphereView(QWidget* parent = nullptr);
    QSlider* getSlider() const;
    QVTKOpenGLNativeWidget* getVTKWidget() const;

private:
    QSlider* radiusSlider;
    QVTKOpenGLNativeWidget* vtkWidget;
};
