#include <gtest/gtest.h>
#include "Model/SphereModel.h"

TEST(SphereModelTest, SetAndGetRadius) {
    SphereModel model;

    model.setRadius(10.0);
    ASSERT_EQ(model.getRadius(), 10.0);

    model.setRadius(20.0);
    ASSERT_EQ(model.getRadius(), 20.0);
}

TEST(SphereModelTest, DefaultRadius) {
    SphereModel model;
    ASSERT_EQ(model.getRadius(), 5.0);
}
