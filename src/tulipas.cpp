#include "tulipas.h"

#define NUM_LEDS 16
#define DATA_PIN 4

#define PIXELPTULIPA 4

#define NUM_TULIPAS 4

CRGB ArrayLeds[NUM_LEDS];

void tulipas_c::init(uint8_t _col, uint8_t _row, uint8_t _pos) {
    col = _col;
    row = _row;
    pos = _pos;
    firstLed = pos * PIXELPTULIPA;

    for(int i = 0; i < PIXELPTULIPA; i++) {
        leds[i] = &ArrayLeds[firstLed + i];
    }
}
void tulipas_c::setColor(CRGB color) {
    for(int i = 0; i < PIXELPTULIPA; i++) { *leds[i] = color; }
}

tulipas_c tulipa[NUM_TULIPAS];

void init_tulipas() {
    pinMode(DATA_PIN, OUTPUT);
    FastLED.addLeds<WS2811, DATA_PIN, BRG>(ArrayLeds, NUM_LEDS);

    tulipa[0].init(1, 1, 0);
    tulipa[1].init(1, 2, 1);
    tulipa[2].init(1, 3, 2);
    tulipa[3].init(1, 4, 3);

    tulipa[0].setColor(CRGB::Purple);
    tulipa[1].setColor(CRGB::Blue);
    tulipa[2].setColor(CRGB::Green);
    tulipa[3].setColor(CRGB::WhiteSmoke);
}

void handle_tulipas() {
    if(!digitalRead(BUTTON_BLUE)) {
        for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CRGB::Blue); }
    }
    if(!digitalRead(BUTTON_YELLOW)) {
        for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CRGB::Yellow); }
    }
    if(!digitalRead(BUTTON_GREEN)) {
        for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CRGB::Green); }
    }

    FastLED.show(map(analogRead(0), 0, 1023, 0, 255));
    delay(10);
}