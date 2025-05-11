#pragma once

class SphereSettings {
    public:
    SphereSettings();

    double radius;
    int phi_resolution;
    int theta_resolution;
    int rand_seed;
    int current_rand;
};

class QtSettings {
    public:
    QtSettings();

    int radius_min;
    int radius_max;
};
