#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "Model/SphereModel.h"
#include "Controller/SphereController.h"
#include "View/SphereView.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    QMainWindow* mainWindow = new QMainWindow;
    SphereModel model;
    SphereView view;
    SphereController controller(&model, &view);
    mainWindow->setCentralWidget(view.getQVNativeWidget());
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, view.getControlDock());
    mainWindow->resize(1200, 800);
    mainWindow->show();
    return app.exec();
}
