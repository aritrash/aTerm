# aTerm

**aTerm** is the official desktop console and development terminal for **aTOS (aether Ternary Operating System)**.

It provides a dedicated communication interface between a host computer and an aTOS system running on supported hardware such as the ESP32. Unlike traditional serial terminals, aTerm is designed specifically around the requirements of aTOS and the TPA-1 research ecosystem.

---

## Project Status

Current Version: **0.1.0**

Development Status: **Early Development**

---

## Features

Current goals include:

- UART serial communication
- Cross-platform desktop application
- Custom aTOS console protocol
- 16-colour terminal rendering
- Keyboard input forwarding
- Session logging

Future goals include:

- Splash screen rendering
- Register viewer
- Memory inspector
- Tryte inspector
- Kernel debugger
- Multi-target support
- TPA-1 hardware compatibility

---

## Technology Stack

- C++20
- Qt 6
- Qt Serial Port
- CMake

---

## Repository Structure

```
aTerm/

├── assets/
├── docs/
├── include/
├── src/
├── tests/

├── CMakeLists.txt
├── LICENSE
├── README.md
└── .gitignore
```

---

## Relationship with aTOS

aTerm is **not** a general-purpose serial terminal.

It is the official development console for aTOS.

The communication protocol is intentionally designed around the needs of the aTOS operating environment rather than ANSI terminal compatibility.

---

## License

MIT License

---

## Author

Aritrash Sarkar
