#include "SphereModel.h"

SphereModel::SphereModel() : radius(1.0), th_res(100), phi_res(100),
sphereSource(vtkSmartPointer<vtkSphereSource>::New()) {
    sphereSource->SetRadius(radius);
    sphereSource->SetThetaResolution(th_res);
    sphereSource->SetPhiResolution(phi_res);
    sphereSource->Update();
}

void SphereModel::setRadius(double r) {
    radius = r;
    sphereSource->SetRadius(radius);
    sphereSource->Update();
}
void SphereModel::setResolution(int t_r, int ph_r) {
    sphereSource->SetThetaResolution(t_r);
    sphereSource->SetPhiResolution(ph_r);
    sphereSource->Update();
}

double SphereModel::getRadius() const {
    return radius;
}

vtkSmartPointer<vtkSphereSource> SphereModel::getSphereSource() const{
    return sphereSource;
}
