#include <QApplication>
#include "atermwindow.hpp"

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    ATermWindow window;

    window.show();

    return application.exec();
}