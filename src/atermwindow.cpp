#include "atermwindow.hpp"

#include <QByteArray>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>
#include <QVector>

#include "machineinfo.hpp"
#include "protocolparser.hpp"
#include "serialdialog.hpp"
#include "serialmanager.hpp"
#include "terminalview.hpp"
#include "version.hpp"

ATermWindow::ATermWindow(QWidget* parent)
    : QMainWindow(parent),
      terminal_(nullptr),
      serial_(nullptr),
      machine_type_(MachineType::Unknown),
      state_label_(nullptr),
      connection_label_(nullptr),
      encoding_label_(nullptr),
      setup_button_(nullptr)
{
    initialize_window();

    terminal_ = new TerminalView;
    terminal_->set_buffer(&terminal_buffer_);
    serial_ = new SerialManager(this);
    setCentralWidget(terminal_);

    connect(
        terminal_,
        &TerminalView::line_entered,
        this,
        [this](const QString& line)
        {
            process_input_line(line);
        });

    connect(
        serial_,
        &SerialManager::data_received,
        this,
        [this](const QByteArray& data)
        {
            process_serial_data(data);
        });

    initialize_status_bar();
}

void ATermWindow::process_input_line(
    const QString& line)
{
    terminal_buffer_.append_line(
        QString("C:\\>%1").arg(line));

    terminal_->update();

    serial_->send_line(line);
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
        "}");
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
    SerialDialog dialog(this);

    if (dialog.exec() != QDialog::Accepted)
        return;

    terminal_->setFocus();

    if (!serial_->connect_port(
            dialog.port_name(),
            dialog.baud_rate()))
    {
        QMessageBox::warning(
            this,
            "Connection Failed",
            "Unable to open the selected serial port.");

        return;
    }

    connection_label_->setText(
        QString("%1 @ %2")
            .arg(dialog.port_name())
            .arg(dialog.baud_rate()));

    state_label_->setText("Connected");
}

void ATermWindow::process_serial_data(const QByteArray& data)
{
    const QVector<ProtocolParser::ParseResult> results =
        parser_.parse(data);

    for (const auto& result : results)
    {
        switch (result.type)
        {
            case ProtocolParser::Result::Hello:
            {
                machine_type_ = result.machine;
                terminal_buffer_.set_machine(machine_type_);
                state_label_->setText("Handshake");
                
                terminal_->update();

                qDebug().noquote()
                    << "[HELLO]"
                    << machine_name(machine_type_);

                break;
            }

            case ProtocolParser::Result::AsciiCommand:
            {
                execute_command(result.text);
                break;
            }

            default:
                break;
        }
    }
}

void ATermWindow::execute_command(
    const QString& command)
{
    if (command == "SHOW_SPLASH")
    {
        terminal_buffer_.set_mode(
            TerminalMode::Splash);

        terminal_buffer_.clear();
        terminal_->update();

        return;
    }

    if (command == "CONSOLE")
    {
        terminal_buffer_.set_mode(
            TerminalMode::Console);

        terminal_buffer_.set_prompt("C:\\> ");
        terminal_->update();

        return;
    }

    if (command == "CLEAR")
    {
        terminal_buffer_.clear();

        terminal_->update();

        return;
    }

    if (command == "PRINT")
    {
        terminal_buffer_.append_line("");

        terminal_->update();

        return;
    }

    if (command.startsWith("PRINT "))
    {
        terminal_buffer_.append_line(
            command.mid(6));

        terminal_->update();

        return;
    }

    qDebug().noquote()
        << "[UNKNOWN]"
        << command;
}