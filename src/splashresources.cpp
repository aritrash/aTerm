#include "splashresources.hpp"

QString splash_resource(MachineType machine)
{
    switch (machine)
    {
        case MachineType::ESP32:
            return ":/assets/splash/esp32.png";

        case MachineType::ESP8266:
            return ":/assets/splash/esp8266.png";

        case MachineType::STM32F103:
            return ":/assets/splash/stm32f103.png";

        case MachineType::STM32F407:
            return ":/assets/splash/stm32f407.png";

        case MachineType::Teensy31:
            return ":/assets/splash/teensy31.png";

        case MachineType::Teensy40:
            return ":/assets/splash/teensy40.png";

        case MachineType::RaspberryPi3:
            return ":/assets/splash/rpi3.png";

        case MachineType::RaspberryPi4:
            return ":/assets/splash/rpi4.png";

        case MachineType::RaspberryPi5:
            return ":/assets/splash/rpi5.png";

        case MachineType::RaspberryPiCM4:
            return ":/assets/splash/rpi_cm4.png";

        case MachineType::RaspberryPiCM5:
            return ":/assets/splash/rpi_cm5.png";

        default:
            return ":/assets/splash/unknown.png";
    }
}