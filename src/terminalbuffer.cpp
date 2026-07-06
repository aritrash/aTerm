#include "terminalbuffer.hpp"

TerminalBuffer::TerminalBuffer()
    : mode_(TerminalMode::Console)
{
    console_text_ =
        "aTerm\n\n"
        "Desktop Console for aTOS\n\n"
        "Waiting for connection...";
}

void TerminalBuffer::set_mode(TerminalMode mode)
{
    mode_ = mode;
}

TerminalMode TerminalBuffer::mode() const
{
    return mode_;
}

const QString& TerminalBuffer::console_text() const
{
    return console_text_;
}

void TerminalBuffer::set_console_text(
    const QString& text)
{
    console_text_ = text;
}

void TerminalBuffer::append_line(
    const QString& line)
{
    if (!console_text_.isEmpty())
        console_text_ += '\n';

    console_text_ += line;
}