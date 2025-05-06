#pragma once
#include <QApplication>
#include <QDockWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPointer.h>
#include <QPushButton>
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
    explicit SphereView(QWidget* parent = nullptr);
    QDockWidget* getControlDock() const;
    QVTKOpenGLNativeWidget* getQVNativeWidget() const;
    QPushButton* getRandButton() const;

private:
    QDockWidget* controlDock;
    QLabel* controlDockTitle;
    QVBoxLayout* qvBoxLayout;
    QPushButton* randButton;
    QVTKOpenGLNativeWidget* qvtkNativeWidget;

};