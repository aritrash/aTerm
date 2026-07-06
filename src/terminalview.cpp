#include "terminalview.hpp"

#include <QFont>
#include <QPainter>
#include <QRect>

TerminalView::TerminalView(QWidget* parent)
    : QWidget(parent)
{
    initialize_terminal();
}

void TerminalView::initialize_terminal()
{
    setAutoFillBackground(false);

    setFocusPolicy(Qt::StrongFocus);

    QFont terminal_font;

    terminal_font.setFamilies(
    {
        "Consolas",
        "Cascadia Mono",
        "Courier New"
    });

    terminal_font.setPointSize(12);
    terminal_font.setStyleHint(QFont::Monospace);

    setFont(terminal_font);

    display_text_ =
        "aTerm\n\n"
        "Desktop Console for aTOS\n\n"
        "Waiting for connection...";
}

void TerminalView::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    painter.setRenderHint(QPainter::TextAntialiasing, true);

    painter.setPen(Qt::black);

    painter.setFont(font());

    painter.drawText(
        rect(),
        Qt::AlignCenter,
        display_text_);
}