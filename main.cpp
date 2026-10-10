// main.cpp
// Qt starting point. Just opens the main window.

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("College Lost and Found System");
    window.resize(800, 600);
    window.show();
    return app.exec();
}
