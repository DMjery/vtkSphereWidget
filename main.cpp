#include <QApplication>
#include "Model/SphereModel.h"
#include "View/SphereView.h"
#include "Controller/SphereController.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    SphereModel model;
    SphereView view;
    SphereController controller(&model, &view);

    view.show();
    return app.exec();
}
