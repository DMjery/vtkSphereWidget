#include <gtest/gtest.h>
#include <QApplication>
#include "SphereView.h"


class SphereViewTest : public ::testing::Test {
protected:
    SphereView view;
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

QApplication* SphereViewTest::app = nullptr;
int SphereViewTest::argc = 0;
char** SphereViewTest::argv = nullptr;

TEST_F(SphereViewTest, DefaultConstructorInitializesCorrectly) {
    SphereView view;
    EXPECT_NE(view.getRandButton(), nullptr);
    EXPECT_NE(view.getQVNativeWidget(), nullptr);
    EXPECT_NE(view.getControlDock(), nullptr);
    EXPECT_TRUE(view.getControlDock()->widget()->children().contains(view.getRandButton()));
}

