#include <gtest/gtest.h>
#include "View/SphereView.h"

TEST(SphereViewTest, SliderInitialization) {
    SphereView view;

    ASSERT_EQ(view.getSlider()->value(), 5);
}
