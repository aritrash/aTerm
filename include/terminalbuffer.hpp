#pragma once

#include <QString>
#include <QStringList>

#include "machinetype.hpp"

enum class TerminalMode
{
    Splash,
    Console
};

class TerminalBuffer
{
public:

    TerminalBuffer();
    void set_mode(TerminalMode mode);

    [[nodiscard]]
    TerminalMode mode() const;

    [[nodiscard]]
    QString console_text() const;

    void set_machine(MachineType machine);

    [[nodiscard]]
    MachineType machine() const;

    void set_console_text(const QString& text);
    void append_line(const QString& line);
    void clear();
    void set_prompt(const QString& prompt);

    [[nodiscard]]
    const QString& prompt() const;

    void set_input_line(const QString& line);

    [[nodiscard]]
    const QString& input_line() const;

    [[nodiscard]]
    const QStringList& lines() const;

    QString display_text() const;

private:

    TerminalMode mode_;
    QStringList console_lines_;
    MachineType machine_;
    QString prompt_;
    QString input_line_;
};