#include "atermwindow.hpp"

#include <QLabel>
#include <QStatusBar>
#include <QMessageBox>

#include "terminalview.hpp"
#include "version.hpp"

ATermWindow::ATermWindow(QWidget* parent)
    : QMainWindow(parent),
      terminal_(nullptr),
      state_label_(nullptr),
      connection_label_(nullptr),
      encoding_label_(nullptr),
      setup_button_(nullptr)
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
        "QPushButton {"
        "background: #F4F4F4;"
        "color: #202020;"
        "border: 1px solid #C0C0C0;"
        "padding-left: 10px;"
        "padding-right: 10px;"
        "min-height: 22px;"
        "}"

        "QPushButton:hover {"
        "background: #E8E8E8;"
        "}"

        "QPushButton:pressed {"
        "background: #DCDCDC;"
        "}"
    );
}

void ATermWindow::initialize_status_bar()
{
    state_label_ = new QLabel("Ready");

    connection_label_ = new QLabel("Disconnected");

    encoding_label_ = new QLabel("UTF-8");

    setup_button_ = new QPushButton("Setup");
    setup_button_->setFixedWidth(72);

    connect(
        setup_button_,
        &QPushButton::clicked,
        this,
        &ATermWindow::on_setup_clicked);

    statusBar()->addWidget(state_label_, 1);

    statusBar()->addPermanentWidget(connection_label_);

    statusBar()->addPermanentWidget(encoding_label_);

    statusBar()->addPermanentWidget(setup_button_);
}

void ATermWindow::on_setup_clicked()
{
    QMessageBox::information(
        this,
        "Setup",
        "Serial configuration dialog coming soon.");
}