#pragma once

#include <QPaintEvent>
#include <QWidget>
#include <QString>
#include <QWheelEvent>
#include "terminalbuffer.hpp"

class QPainter;

class TerminalView final : public QWidget
{
    Q_OBJECT
public:

    explicit TerminalView(QWidget* parent = nullptr);

    ~TerminalView() override = default;

    void set_buffer(TerminalBuffer* buffer);
    void refresh();

protected:

    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:

    void initialize_terminal();
    void draw_console(QPainter& painter);
    void follow_bottom();
    void draw_splash(QPainter& painter);

private:

    TerminalBuffer* buffer_;
    int scroll_offset_;

signals:

    void line_entered(const QString& line);
};