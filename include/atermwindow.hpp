#pragma once

#include <QMainWindow>

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

private:

    TerminalView* terminal_;

    QLabel* state_label_;

    QLabel* connection_label_;

    QLabel* encoding_label_;

};