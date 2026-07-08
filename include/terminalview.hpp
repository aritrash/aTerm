#pragma once

#include <QPaintEvent>
#include <QWidget>
#include <QString>

#include "terminalbuffer.hpp"

class QPainter;

class TerminalView final : public QWidget
{
    Q_OBJECT
public:

    explicit TerminalView(QWidget* parent = nullptr);

    ~TerminalView() override = default;

    void set_buffer(const TerminalBuffer* buffer);

protected:

    void paintEvent(QPaintEvent* event) override;

    void keyPressEvent(QKeyEvent* event) override;

private:

    void initialize_terminal();

    void draw_console(QPainter& painter);

    void draw_splash(QPainter& painter);

private:

    const TerminalBuffer* buffer_;

    QString input_line_;

signals:

    void line_entered(const QString& line);
};