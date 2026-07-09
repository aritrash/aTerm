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

    prompt_.clear();
}

void TerminalBuffer::set_prompt(
    const QString& prompt)
{
    prompt_ = prompt;
}

const QString&
TerminalBuffer::prompt() const
{
    return prompt_;
}

void TerminalBuffer::set_input_line(
    const QString& line)
{
    input_line_ = line;
}

const QString&
TerminalBuffer::input_line() const
{
    return input_line_;
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

QString TerminalBuffer::display_text() const
{
    QString text =
        console_lines_.join('\n');

    if (!text.isEmpty())
        text += '\n';

    text += prompt_;
    text += input_line_;

    return text;
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