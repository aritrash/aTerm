#pragma once

#include <QPaintEvent>
#include <QWidget>

#include "terminalbuffer.hpp"

class QPainter;

class TerminalView final : public QWidget
{
public:

    explicit TerminalView(QWidget* parent = nullptr);

    ~TerminalView() override = default;

protected:

    void paintEvent(QPaintEvent* event) override;

private:

    void initialize_terminal();

    void draw_console(QPainter& painter);

    void draw_splash(QPainter& painter);

    TerminalBuffer buffer_;

};