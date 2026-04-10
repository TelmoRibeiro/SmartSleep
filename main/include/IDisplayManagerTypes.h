#pragma once

#include <stdint.h>

enum class TextFontSize : uint8_t {
    Font4x6,
    Font5x7
};

enum class ScrollDirection : uint32_t {
    Static    = 0,
    Leftward  = 1,
    Rightward = 2,
    Upward    = 3,
    Downward  = 4
};
