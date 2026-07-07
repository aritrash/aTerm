#include "terminalbuffer.hpp"

static constexpr int MAX_CONSOLE_LINES = 100;

TerminalBuffer::TerminalBuffer()
    : mode_(TerminalMode::Console),
      machine_(MachineType::Unknown)
{
    console_lines_ = {
        "aTerm",
        "",
        "Desktop Console for aTOS",
        "",
        "Waiting for connection..."
    };
}

void TerminalBuffer::set_machine(
    MachineType machine)
{
    machine_ = machine;
}

MachineType TerminalBuffer::machine() const
{
    return machine_;
}

void TerminalBuffer::set_mode(TerminalMode mode)
{
    mode_ = mode;
}

TerminalMode TerminalBuffer::mode() const
{
    return mode_;
}

QString TerminalBuffer::console_text() const
{
    return console_lines_.join('\n');
}

void TerminalBuffer::set_console_text(
    const QString& text)
{
    console_lines_ =
        text.split(
            '\n',
            Qt::KeepEmptyParts);
}

void TerminalBuffer::append_line(
    const QString& line)
{
    console_lines_.append(line);
    while (console_lines_.size() > MAX_CONSOLE_LINES)
        console_lines_.removeFirst();
}

void TerminalBuffer::clear()
{
    console_lines_.clear();
}