#pragma once

#include <QString>

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
    const QString& console_text() const;

    void set_console_text(const QString& text);

    void append_line(const QString& line);

private:

    TerminalMode mode_;

    QString console_text_;

};