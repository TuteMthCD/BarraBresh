#include "Arduino.h"
#include "FastLED.h"

#define NUM_ROWS_LGBT 7
#define NUM_COLS_LGBT 7

CRGB lgbt[NUM_ROWS_LGBT][NUM_COLS_LGBT] = {
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 1
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 2
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 3
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 4
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 5
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }, // 6
    { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Cyan, CRGB::Blue, CRGB::Purple }  // 7
};

#define NUM_ROWS_TRANS 7
#define NUM_COLS_TRANS 7

CRGB trans[NUM_ROWS_TRANS][NUM_COLS_TRANS] = {
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    { CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia, CRGB::Cyan, CRGB::Fuchsia },
    };