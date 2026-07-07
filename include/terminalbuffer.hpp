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

private:

    TerminalMode mode_;
    QStringList console_lines_;
    MachineType machine_;

};