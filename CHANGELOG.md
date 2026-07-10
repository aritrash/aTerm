# Changelog

All notable changes to aTerm will be documented in this file.

## [0.2.0] - 2026-07-09

### Added

- Interactive serial console
- ESP32 machine detection
- Custom UART protocol
- Board-specific splash screens
- Keyboard input
- Line-based UART framing
- Console rendering engine
- Binary HELLO handshake

### Improved

- Cleaner terminal rendering
- Proper prompt rendering
- Interactive command entry
- Cross-platform Qt6 desktop application

### Fixed

- UART packet fragmentation
- Double prompt rendering
- Splash resource loading
- Terminal focus handling

# v0.2.1

## Added
- Mouse wheel scrolling.
- Terminal viewport rendering.
- Auto-follow mode for live output.
- Refresh API for terminal updates.

## Changed
- Terminal now renders line-by-line instead of as one large text block.
- Improved rendering architecture for future ANSI support.
- Improved scrollback handling for long boot logs.

## Fixed
- Boot logs no longer disappear beyond the window.