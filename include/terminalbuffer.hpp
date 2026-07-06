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

private:

    TerminalMode mode_;

    QString console_text_;

};