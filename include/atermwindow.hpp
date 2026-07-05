#pragma once

#include <QMainWindow>

class ATermWindow final : public QMainWindow
{
public:

    explicit ATermWindow(QWidget* parent = nullptr);
    ~ATermWindow() override = default;

private:

    void initialize_window();

};