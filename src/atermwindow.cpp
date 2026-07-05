#include "atermwindow.hpp"
#include <QIcon>
#include "version.hpp"

ATermWindow::ATermWindow(QWidget* parent)
    : QMainWindow(parent)
{
    initialize_window();
}

void ATermWindow::initialize_window()
{
    setWindowTitle(
        QString("%1 %2")
            .arg(version::NAME)
            .arg(version::VERSION_STRING)
    );

    resize(1280, 720);

    setMinimumSize(960, 540);

    setUnifiedTitleAndToolBarOnMac(false);

    // Uncomment after adding an icon.
    // setWindowIcon(QIcon("assets/icon.ico"));
}