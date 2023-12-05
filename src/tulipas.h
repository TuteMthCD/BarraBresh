#include <Arduino.h>
#include <FastLED.h>

#define BUTTON_WHITE 15
#define BUTTON_YELLOW 2
#define BUTTON_GREEN 0
#define BUTTON_BLUE 5

void init_tulipas();
void handle_tulipas();


class tulipas_c {
    private:
    public:
    uint8_t col, row, firstLed, pos;

    CRGB *leds[4] = {NULL, NULL, NULL, NULL};
    void init(uint8_t col, uint8_t row, uint8_t pos);
    void setColor(CRGB color);
};