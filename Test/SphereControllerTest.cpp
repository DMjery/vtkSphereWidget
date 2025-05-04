#include <gtest/gtest.h>
#include <QSlider>
#include <QObject>
#include "Controller/SphereController.h"
#include "Model/SphereModel.h"
#include "View/SphereView.h"

TEST(SphereControllerTest, SliderValueChanged) {
    SphereModel model;
    SphereView view;
    SphereController controller(&model, &view);

    // Simulate slider signal
    emit view.getSlider()->valueChanged(42);

    EXPECT_DOUBLE_EQ(model.getRadius(), 42.0);
}
