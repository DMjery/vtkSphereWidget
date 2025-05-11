#include "SphereView.h"
#include "SphereSettings.h"



SphereView::SphereView(QWidget* parent) : QWidget(parent) {
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());


    // VTK Widget (Main rendering area)
    qvtkNativeWidget = new QVTKOpenGLNativeWidget(this);

    controlDock = new QDockWidget("Sphere Control", this);
    controlDock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::LeftDockWidgetArea);

    controlDockTitle = new QLabel("Control Dock", this);
    controlDockTitle->setMargin(5);
    controlDock->setTitleBarWidget(controlDockTitle);

    QWidget* dockContent = new QWidget(this);
    gridLayout = new QGridLayout(dockContent);

    randButton = new QPushButton("Randomize", dockContent);
    radiusSlider = new QSlider(Qt::Vertical, dockContent);
    QLabel* radiusLabel = new QLabel("Radius", dockContent);

    radiusSlider->setValue(1.0);
    radiusSlider->setMaximum(100);
    radiusSlider->setMinimum(1);
    // qvBoxLayout->addWidget(randButton);
    gridLayout->addWidget(randButton, 3, 0, 1, 2);
    gridLayout->addWidget(radiusLabel, 4,0, Qt::AlignCenter);
    gridLayout->addWidget(radiusSlider, 4, 1,Qt::AlignCenter);
    dockContent->setLayout(gridLayout);
    controlDock->setWidget(dockContent);

    // Layout
    QGridLayout* mainLayout = new QGridLayout(this);
    // auto* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(qvtkNativeWidget);
    setLayout(mainLayout);

}

QDockWidget* SphereView::getControlDock() const {
    return controlDock;
};


QPushButton* SphereView::getRandButton() const {
    return randButton;
}

QSlider* SphereView::getSlider() const {
    return radiusSlider;
}

QVTKOpenGLNativeWidget* SphereView::getQVNativeWidget () const {
    return qvtkNativeWidget;
}


