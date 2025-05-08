#include <gtest/gtest.h>
#include "SphereModel.h"

class SphereModelTest : public ::testing::Test {
protected:
    SphereModel model;
};

TEST_F(SphereModelTest, DefaultConstructorInitializesCorrectly) {
    auto sphere = model.getSphereSource();
    EXPECT_NE(sphere, nullptr);
    EXPECT_DOUBLE_EQ(model.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(sphere->GetRadius(), 1.0);
    EXPECT_EQ(sphere->GetThetaResolution(), 100);
    EXPECT_EQ(sphere->GetPhiResolution(), 100);
}

TEST_F(SphereModelTest, SetRadiusUpdatesModelAndSphereSource) {
    model.setRadius(5.5);
    auto sphere = model.getSphereSource();

    EXPECT_DOUBLE_EQ(model.getRadius(), 5.5);
    EXPECT_DOUBLE_EQ(sphere->GetRadius(), 5.5);
}

TEST_F(SphereModelTest, SetResolutionUpdatesSphereSource) {
    model.setResolution(20, 10);
    auto sphere = model.getSphereSource();

    EXPECT_EQ(sphere->GetThetaResolution(), 20);
    EXPECT_EQ(sphere->GetPhiResolution(), 10);
}

TEST_F(SphereModelTest, MultipleUpdatesRemainConsistent) {
    model.setRadius(2.2);
    model.setResolution(64, 32);
    auto sphere = model.getSphereSource();

    EXPECT_DOUBLE_EQ(model.getRadius(), 2.2);
    EXPECT_DOUBLE_EQ(sphere->GetRadius(), 2.2);
    EXPECT_EQ(sphere->GetThetaResolution(), 64);
    EXPECT_EQ(sphere->GetPhiResolution(), 32);
}
