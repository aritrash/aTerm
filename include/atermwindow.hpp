#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QByteArray>
#include "terminalbuffer.hpp"
#include "protocolparser.hpp"
#include "machinetype.hpp"

class QLabel;
class TerminalView;
class SerialManager;

class ATermWindow final : public QMainWindow
{
public:

    explicit ATermWindow(QWidget* parent = nullptr);
    ~ATermWindow() override = default;

private:

    void initialize_window();
    void initialize_status_bar();
    void on_setup_clicked();
    void process_serial_data(const QByteArray& data);
    void execute_command(const QString& command);

private:

    TerminalView* terminal_;
    TerminalBuffer terminal_buffer_;
    QLabel* state_label_;
    QLabel* connection_label_;
    QLabel* encoding_label_;
    QPushButton* setup_button_;
    SerialManager* serial_;
    ProtocolParser parser_;
    MachineType machine_type_;

};