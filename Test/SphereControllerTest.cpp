#include <gtest/gtest.h>
#include <QApplication>
#include "Model/SphereModel.h"
#include "View/SphereView.h"
#include "Controller/SphereController.h"
#include <QTest>


class SphereControllerTest : public ::testing::Test {
protected:
    static QApplication* app;
    static int argc;
    static char** argv;
public:
    static void SetUpTestSuite() {
        if (app == nullptr) {
            app = new QApplication(argc, argv);
        }
    }
    static void TearDownTestSuite() {
        delete app;
        app = nullptr;
    }
};

QApplication* SphereControllerTest::app = nullptr;
int SphereControllerTest::argc = 0;
char** SphereControllerTest::argv = nullptr;


// Assert the Controller is successfully initialized by default contsructor
TEST_F(SphereControllerTest, SphereController) {
    SphereView view;
    SphereModel model;
    SphereController controller(&model, &view);

    ASSERT_EQ(&model, controller.getModel());
    ASSERT_EQ(&view, controller.getView());
    ASSERT_NE(view.getQVNativeWidget()->renderWindow(), nullptr);

    QPushButton* button = view.getRandButton();
    QTest::mouseClick(button, Qt::LeftButton);
}
