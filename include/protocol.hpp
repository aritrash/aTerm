#pragma once

#include <cstdint>

namespace protocol
{
    constexpr std::uint8_t SYNC = 0xA5;
    constexpr std::uint8_t VERSION = 0x01;

    enum class PacketType : std::uint8_t
    {
        Hello = 0x01,
        TerminalCommand = 0x02,
        Heartbeat = 0x03,
        Reserved = 0xFF
    };

    enum class TerminalCommand : std::uint8_t
    {
        ShowSplash = 0x01,
        Console = 0x02,
        Print = 0x03,
        Clear = 0x04,
        Prompt = 0x05
    };
}