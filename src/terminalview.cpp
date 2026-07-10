#include "terminalview.hpp"
#include "splashresources.hpp"
#include "theme.hpp"

#include <QFile>
#include <QFont>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QRect>
#include <algorithm>

TerminalView::TerminalView(QWidget* parent)
    : QWidget(parent),
      buffer_(nullptr),
      scroll_offset_(0)
{
    initialize_terminal();
}

void TerminalView::set_buffer(
    TerminalBuffer* buffer)
{
    buffer_ = buffer;
    follow_bottom();
}

void TerminalView::refresh()
{
    follow_bottom();
    update();
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

    terminal_font.setPointSize(
        theme::font::TERMINAL_SIZE);

    terminal_font.setStyleHint(
        QFont::Monospace);

    setFont(terminal_font);
}

void TerminalView::follow_bottom()
{
    if (!buffer_)
        return;

    constexpr int MARGIN = 12;

    const QRect console_rect =
        rect().adjusted(
            MARGIN,
            MARGIN,
            -MARGIN,
            -MARGIN);

    const QFontMetrics metrics(font());

    const int visible_lines =
        console_rect.height() /
        metrics.height();

    const int max_offset =
        std::max(
            0,
            static_cast<int>(
                buffer_->lines().size()) -
            visible_lines);

    scroll_offset_ = max_offset;
}

void TerminalView::paintEvent(
    QPaintEvent* event)
{
    if (!buffer_)
        return;

    QWidget::paintEvent(event);

    QPainter painter(this);

    painter.fillRect(
        rect(),
        theme::colour::BACKGROUND);

    painter.setRenderHint(
        QPainter::TextAntialiasing,
        true);

    painter.setPen(
        theme::colour::FOREGROUND);

    painter.setFont(font());

    switch (buffer_->mode())
    {
        case TerminalMode::Splash:
            draw_splash(painter);
            break;

        case TerminalMode::Console:
        default:
            draw_console(painter);
            break;
    }
}

void TerminalView::draw_console(
    QPainter& painter)
{
    constexpr int MARGIN = 12;

    const QRect console_rect =
        rect().adjusted(
            MARGIN,
            MARGIN,
            -MARGIN,
            -MARGIN);

    const auto& lines =
        buffer_->lines();

    QFontMetrics metrics(font());

    const int visible_lines =
        console_rect.height() /
        metrics.height();

    const int max_offset =
        std::max(
            0,
            static_cast<int>(lines.size()) -
            visible_lines);

    if (scroll_offset_ > max_offset)
        scroll_offset_ = max_offset;

    const int line_height =
        metrics.height();

    const int first_line =
        scroll_offset_;

    const int last_line =
        std::min(
            first_line + visible_lines,
            static_cast<int>(lines.size()));

    int y =
        console_rect.top() +
        metrics.ascent();

    for (int i = first_line;
         i < last_line;
         ++i)
    {
        painter.drawText(
            console_rect.left(),
            y,
            lines[i]);

        y += line_height;
    }

    const bool at_bottom =
        (last_line ==
         static_cast<int>(lines.size()));

    if (at_bottom)
    {
        painter.drawText(
            console_rect.left(),
            y,
            buffer_->prompt() +
            buffer_->input_line());
    }
}

void TerminalView::draw_splash(
    QPainter& painter)
{
    const QString path =
        splash_resource(
            buffer_->machine());

    const QPixmap splash(path);

    if (splash.isNull())
    {
        painter.drawText(
            rect(),
            Qt::AlignCenter,
            QString("Missing splash\n%1")
                .arg(path));

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

    painter.drawPixmap(
        position,
        scaled);
}

void TerminalView::keyPressEvent(
    QKeyEvent* event)
{
    if (buffer_->mode() !=
        TerminalMode::Console)
        return;

    switch (event->key())
    {
        case Qt::Key_Return:
        case Qt::Key_Enter:
        {
            emit line_entered(
                buffer_->input_line());

            buffer_->set_input_line("");

            update();
            break;
        }

        case Qt::Key_Backspace:
        {
            QString line =
                buffer_->input_line();

            line.chop(1);

            buffer_->set_input_line(
                line);

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
                QString line =
                    buffer_->input_line();

                line += text;

                buffer_->set_input_line(
                    line);

                update();
            }

            break;
        }
    }
}

void TerminalView::wheelEvent(
    QWheelEvent* event)
{
    if (!buffer_)
        return;

    constexpr int MARGIN = 12;

    const QRect console_rect =
        rect().adjusted(
            MARGIN,
            MARGIN,
            -MARGIN,
            -MARGIN);

    const auto& lines =
        buffer_->lines();

    QFontMetrics metrics(font());

    const int visible_lines =
        console_rect.height() /
        metrics.height();

    const int max_offset =
        std::max(
            0,
            static_cast<int>(lines.size()) -
            visible_lines);

    if (event->angleDelta().y() > 0)
        --scroll_offset_;
    else
        ++scroll_offset_;

    scroll_offset_ =
        std::clamp(
            scroll_offset_,
            0,
            max_offset);

    update();

    event->accept();
}