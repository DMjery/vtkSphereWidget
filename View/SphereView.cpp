#include "SphereView.h"
#include "SphereSettings.h"



SphereView::SphereView(QWidget* parent) : QWidget(parent) {
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

    QtSettings qt_settings;
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
    radiusLabel = new QLabel(dockContent);


    radiusSlider->setValue(0);
    radiusSlider->setMaximum(qt_settings.radius_max/10.0);
    radiusSlider->setMinimum(qt_settings.radius_min/10.0);
    radiusLabel->setText(QString("radius: %1").arg(radiusSlider->value()));
    gridLayout->addWidget(randButton, 3, 0, 1, 2);
    gridLayout->addWidget(radiusLabel, 4,0, Qt::AlignCenter);
    gridLayout->addWidget(radiusSlider, 4, 1,Qt::AlignCenter);
    dockContent->setLayout(gridLayout);
    controlDock->setWidget(dockContent);

    // Layout
    QGridLayout* mainLayout = new QGridLayout(this);
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

void SphereView::update_slider_label() const {
    radiusLabel->setText(QString("radius: %1").arg(radiusSlider->value()/10.0));
}


