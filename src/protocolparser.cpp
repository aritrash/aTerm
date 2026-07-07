#include "protocolparser.hpp"
#include "protocol.hpp"

QVector<ProtocolParser::ParseResult>
ProtocolParser::parse(
    const QByteArray& data)
{
    QVector<ParseResult> results;

    if (data.isEmpty())
        return results;

    int index = 0;

    if (data.size() >= 4 &&
        static_cast<std::uint8_t>(data[0]) == protocol::SYNC &&
        static_cast<std::uint8_t>(data[1]) ==
            static_cast<std::uint8_t>(protocol::PacketType::Hello))
    {
        ParseResult hello;
        hello.type = Result::Hello;
        hello.machine =
            static_cast<MachineType>(
                static_cast<std::uint8_t>(data[3]));

        results.push_back(hello);
        index = 4;
    }

    if (index >= data.size())
        return results;

    const QString remaining =
        QString::fromUtf8(data.mid(index));

    const QStringList lines =
        remaining.split(
            '\n',
            Qt::SkipEmptyParts);

    for (QString line : lines)
    {
        line = line.trimmed();
        if (line.isEmpty())
            continue;

        ParseResult command;
        command.type = Result::AsciiCommand;
        command.text = line;
        results.push_back(command);
    }

    return results;
}