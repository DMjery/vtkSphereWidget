#include "SphereModel.h"



SphereModel::SphereModel() :
sphereSource(vtkSmartPointer<vtkSphereSource>::New()) {
    SphereSettings sphere_settings;
    radius = sphere_settings.radius;
    th_res = sphere_settings.theta_resolution;
    phi_res = sphere_settings.phi_resolution;
    sphereSource->SetRadius(radius);
    sphereSource->SetThetaResolution(th_res);
    sphereSource->SetPhiResolution(phi_res);
    sphereSource->Update();
}

void SphereModel::setRadius(double r) {
    sphere_settings.radius = r;
    sphereSource->SetRadius(r);
    sphereSource->Update();
}

void SphereModel::setCurrentRand(int val) {
    sphere_settings.current_rand = val;
}
void SphereModel::setResolution(int t_r, int ph_r) {
    sphere_settings.theta_resolution = t_r;
    sphere_settings.phi_resolution = ph_r;
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

SphereSettings SphereModel::getSphereSettings(){
    return sphere_settings;
}
