#include "machinetype.hpp"
#include "machineinfo.hpp"

QString machine_name(MachineType machine)
{
    switch (machine)
    {
        case MachineType::ESP32:
            return "ESP32";

        case MachineType::ESP8266:
            return "ESP8266";

        case MachineType::STM32F103:
            return "STM32F103";

        case MachineType::STM32F407:
            return "STM32F407";

        case MachineType::Teensy31:
            return "Teensy 3.1";

        case MachineType::Teensy40:
            return "Teensy 4.0";

        case MachineType::RaspberryPi3:
            return "Raspberry Pi 3";

        case MachineType::RaspberryPi4:
            return "Raspberry Pi 4";

        case MachineType::RaspberryPi5:
            return "Raspberry Pi 5";

        case MachineType::RaspberryPiCM4:
            return "Raspberry Pi Compute Module 4";

        case MachineType::RaspberryPiCM5:
            return "Raspberry Pi Compute Module 5";

        default:
            return "Unknown";
    }
}
