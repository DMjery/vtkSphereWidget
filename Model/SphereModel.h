#pragma once
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>

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
    vtkSmartPointer<vtkSphereSource> getSphereSource() const;

private:
    double radius;
    int th_res;
    int phi_res;
    vtkSmartPointer<vtkSphereSource> sphereSource;
};
