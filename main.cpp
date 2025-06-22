#include <QApplication>
#include "GUI/Builder.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    RozeStealer::Builder builder;
    builder.show();
    
    return app.exec();
}

