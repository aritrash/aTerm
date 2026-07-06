#include "atermwindow.hpp"

#include <QLabel>
#include <QStatusBar>

#include "terminalview.hpp"
#include "version.hpp"

ATermWindow::ATermWindow(QWidget* parent)
    : QMainWindow(parent),
      terminal_(nullptr),
      state_label_(nullptr),
      connection_label_(nullptr),
      encoding_label_(nullptr)
{
    initialize_window();

    terminal_ = new TerminalView;

    setCentralWidget(terminal_);

    initialize_status_bar();
}

void ATermWindow::initialize_window()
{
    setWindowTitle(version::NAME);

    resize(1280, 720);

    setMinimumSize(960, 540);

    setUnifiedTitleAndToolBarOnMac(false);

    statusBar()->setStyleSheet(
        "QStatusBar {"
        "background: #f4f4f4;"
        "border-top: 1px solid #d0d0d0;"
        "color: #202020;"
        "}"
        "QStatusBar::item {"
        "border: none;"
        "}"
        "QLabel {"
        "padding-left: 8px;"
        "padding-right: 8px;"
        "font-family: Consolas;"
        "font-size: 10pt;"
        "color: #202020;"
        "}"
    );
}

void ATermWindow::initialize_status_bar()
{
    state_label_ = new QLabel("Ready");

    connection_label_ = new QLabel("Disconnected");

    encoding_label_ = new QLabel("UTF-8");

    statusBar()->addWidget(state_label_, 1);

    statusBar()->addPermanentWidget(connection_label_);

    statusBar()->addPermanentWidget(encoding_label_);
}