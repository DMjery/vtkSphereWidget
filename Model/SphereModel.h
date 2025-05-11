#pragma once
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <SphereSettings.h>

/**
 * @class SphereModel
 * @brief The SphereModel class represents the data layer of the sphere object.
 * 
 * This class manages the radius of the sphere and provides an interface to update and retrieve the radius value.
 */
class SphereModel {
public:
    SphereModel();
    void setRadius(double r);
    void setResolution(int t_r, int ph_r);
    double getRadius() const;
    void setCurrentRand(int val);
    vtkSmartPointer<vtkSphereSource> getSphereSource() const;
    SphereSettings getSphereSettings();

private:
    double radius;
    int th_res;
    int phi_res;
    vtkSmartPointer<vtkSphereSource> sphereSource;
    SphereSettings sphere_settings;
};
