#pragma once

#include <QByteArray>
#include <QVector>
#include <QString>

#include "machinetype.hpp"

class ProtocolParser final
{
public:

    enum class Result
    {
        None,
        Hello,
        AsciiCommand
    };

    struct ParseResult
    {
        Result type = Result::None;
        MachineType machine = MachineType::Unknown;
        QString text;
    };

public:

    ProtocolParser() = default;
    QVector<ParseResult> parse(
        const QByteArray& data);

};