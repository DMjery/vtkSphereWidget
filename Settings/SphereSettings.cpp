#include "SphereSettings.h"

SphereSettings::SphereSettings() : radius(0.1),
phi_resolution(100),
theta_resolution(100),
rand_seed(20),
current_rand(0) {};

QtSettings::QtSettings() {
    int radius_min = 1;
    int radius_max = 300;
};
