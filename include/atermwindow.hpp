#pragma once

#include <QMainWindow>
#include <QPushButton>

class QLabel;
class TerminalView;

class ATermWindow final : public QMainWindow
{
public:

    explicit ATermWindow(QWidget* parent = nullptr);

    ~ATermWindow() override = default;

private:

    void initialize_window();

    void initialize_status_bar();

    void on_setup_clicked();

private:

    TerminalView* terminal_;

    QLabel* state_label_;

    QLabel* connection_label_;

    QLabel* encoding_label_;

    QPushButton* setup_button_;

};