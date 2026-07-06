#include "terminalview.hpp"

#include "theme.hpp"

#include <QFont>
#include <QPainter>
#include <QRect>

TerminalView::TerminalView(QWidget* parent)
    : QWidget(parent),
      buffer_(nullptr)
{
    initialize_terminal();
}

void TerminalView::set_buffer(
    const TerminalBuffer* buffer)
{
    buffer_ = buffer;
}

void TerminalView::initialize_terminal()
{
    setAutoFillBackground(false);

    setFocusPolicy(Qt::StrongFocus);

    QFont terminal_font;

    terminal_font.setFamilies(
    {
        theme::font::PRIMARY,
        theme::font::FALLBACK_1,
        theme::font::FALLBACK_2
    });

    terminal_font.setPointSize(theme::font::TERMINAL_SIZE);

    terminal_font.setStyleHint(QFont::Monospace);

    setFont(terminal_font);
}

void TerminalView::paintEvent(QPaintEvent* event)
{
    if (!buffer_)
        return;

    QWidget::paintEvent(event);

    QPainter painter(this);

    painter.fillRect(rect(), theme::colour::BACKGROUND);

    painter.setRenderHint(QPainter::TextAntialiasing, true);

    painter.setPen(theme::colour::FOREGROUND);

    painter.setFont(font());

    switch (buffer_->mode())
    {
        case TerminalMode::Splash:

            draw_splash(painter);

            break;

        case TerminalMode::Console:

            draw_console(painter);

            break;

        default:

            draw_console(painter);

            break;
    }
}

void TerminalView::draw_console(QPainter& painter)
{
    painter.drawText(
        rect(),
        Qt::AlignCenter,
        buffer_->console_text());
}

void TerminalView::draw_splash(QPainter& painter)
{
    painter.drawText(
        rect(),
        Qt::AlignCenter,
        "");
}