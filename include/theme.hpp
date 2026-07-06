#pragma once

#include <QColor>

namespace theme
{

namespace colour
{

//==========================================================================
// Primary Colours
//==========================================================================

inline const QColor BACKGROUND{0xFF, 0xFF, 0xFF};

inline const QColor FOREGROUND{0x11, 0x11, 0x11};

inline const QColor BORDER{0xD0, 0xD0, 0xD0};

inline const QColor STATUS_BAR{0xF4, 0xF4, 0xF4};

inline const QColor ACCENT{0x5F, 0x70, 0x70};

//==========================================================================
// Status Colours
//==========================================================================

inline const QColor SUCCESS{0x2E, 0x7D, 0x32};

inline const QColor WARNING{0xC4, 0x90, 0x00};

inline const QColor ERROR{0xB0, 0x00, 0x20};

inline const QColor DISABLED{0x80, 0x80, 0x80};

}

//==========================================================================
// Fonts
//==========================================================================

namespace font
{

inline constexpr char PRIMARY[] = "Consolas";

inline constexpr char FALLBACK_1[] = "Cascadia Mono";

inline constexpr char FALLBACK_2[] = "Courier New";

inline constexpr int TERMINAL_SIZE = 12;

inline constexpr int STATUS_SIZE = 10;

}

//==========================================================================
// Layout
//==========================================================================

namespace layout
{

inline constexpr int WINDOW_WIDTH = 1280;

inline constexpr int WINDOW_HEIGHT = 720;

inline constexpr int MINIMUM_WIDTH = 960;

inline constexpr int MINIMUM_HEIGHT = 540;

inline constexpr int STATUS_PADDING = 8;

}

}