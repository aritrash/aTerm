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