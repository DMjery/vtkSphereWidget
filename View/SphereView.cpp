#include "SphereView.h"

SphereView::SphereView(QWidget* parent)
    : QWidget(parent), radiusSlider(new QSlider(Qt::Horizontal)), vtkWidget(new QVTKOpenGLNativeWidget) {
    
    radiusSlider->setMinimum(1);
    radiusSlider->setMaximum(100);
    radiusSlider->setValue(5);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(vtkWidget);
    layout->addWidget(radiusSlider);
    setLayout(layout);
}

QSlider* SphereView::getSlider() const {
    return radiusSlider;
}

QVTKOpenGLNativeWidget* SphereView::getVTKWidget() const {
    return vtkWidget;
}
