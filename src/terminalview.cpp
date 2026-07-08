#include "terminalview.hpp"
#include "splashresources.hpp"
#include "theme.hpp"

#include <QFont>
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QKeyEvent>

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
    setFocus();
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
    constexpr int MARGIN = 12;

    const QRect console_rect =
        rect().adjusted(
            MARGIN,
            MARGIN,
            -MARGIN,
            -MARGIN);

    QString display =
        buffer_->console_text();

    if (!display.isEmpty())
        display += '\n';

    display += input_line_;

    painter.drawText(
        console_rect,
        Qt::AlignLeft |
        Qt::AlignTop,
        display);
}

void TerminalView::draw_splash(QPainter& painter)
{
    const QString path =
        splash_resource(buffer_->machine());

    const QPixmap splash(path);

    if (splash.isNull())
    {
        painter.drawText(
            rect(),
            Qt::AlignCenter,
            QString("Missing splash\n%1").arg(path));

        return;
    }

    constexpr double SCALE = 0.75;

    const QSize target_size(
        static_cast<int>(width() * SCALE),
        static_cast<int>(height() * SCALE));

    const QPixmap scaled =
        splash.scaled(
            target_size,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation);

    const QPoint position(
        (width() - scaled.width()) / 2,
        (height() - scaled.height()) / 2);

    painter.drawPixmap(position, scaled);
}

void TerminalView::keyPressEvent(
    QKeyEvent* event)
{
    if (buffer_->mode() != TerminalMode::Console)
        return;

    switch (event->key())
    {
        case Qt::Key_Return:
        case Qt::Key_Enter:
        {
            emit line_entered(input_line_);

            input_line_.clear();

            update();

            break;
        }

        case Qt::Key_Backspace:
        {
            if (!input_line_.isEmpty())
                input_line_.chop(1);

            update();

            break;
        }

        default:
        {
            const QString text =
                event->text();

            if (!text.isEmpty() &&
                text[0].isPrint())
            {
                input_line_ += text;

                update();
            }

            break;
        }
    }
}