#pragma once

#include <cstdint>

enum class MachineType : std::uint8_t
{
    Unknown     = 0x00,

    ESP32       = 0x01,
    ESP8266     = 0x02,

    STM32F103   = 0x10,
    STM32F407   = 0x11,

    Teensy31    = 0x20,
    Teensy40    = 0x21,

    RaspberryPi3 = 0x30,
    RaspberryPi4 = 0x31,
    RaspberryPi5 = 0x32,
    RaspberryPiCM4 = 0x33,
    RaspberryPiCM5 = 0x34
};