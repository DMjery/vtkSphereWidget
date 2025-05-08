#include "SphereView.h"

SphereView::SphereView(QWidget* parent) : QWidget(parent) {
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());


    // VTK Widget (Main rendering area)
    qvtkNativeWidget = new QVTKOpenGLNativeWidget(this);

    controlDock = new QDockWidget("Sphere Control", this);
    controlDock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::LeftDockWidgetArea);

    controlDockTitle = new QLabel("Control Dock", this);
    controlDockTitle->setMargin(10);
    controlDock->setTitleBarWidget(controlDockTitle);

    QWidget* dockContent = new QWidget(this);
    qvBoxLayout = new QVBoxLayout(dockContent);

    randButton = new QPushButton("Randomize", dockContent);
    qvBoxLayout->addWidget(randButton);
    dockContent->setLayout(qvBoxLayout);
    controlDock->setWidget(dockContent);

    // Layout
    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(qvtkNativeWidget);
    setLayout(mainLayout);

}

QDockWidget* SphereView::getControlDock() const {
    return controlDock;
};


QPushButton* SphereView::getRandButton() const {
    return randButton;
}
QVTKOpenGLNativeWidget* SphereView::getQVNativeWidget () const {
    return qvtkNativeWidget;
}


