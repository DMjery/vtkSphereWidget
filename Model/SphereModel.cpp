#include "SphereModel.h"

SphereModel::SphereModel()
    : radius(5.0), sphereSource(vtkSmartPointer<vtkSphereSource>::New()) {
    sphereSource->SetRadius(radius);
    sphereSource->Update();
}

void SphereModel::setRadius(double r) {
    radius = r;
    sphereSource->SetRadius(radius);
    sphereSource->Update();
}

double SphereModel::getRadius() const {
    return radius;
}

vtkSmartPointer<vtkSphereSource> SphereModel::getSphereSource() const {
    return sphereSource;
}
