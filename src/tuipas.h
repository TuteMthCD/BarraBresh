#include <Arduino.h>
#include <FastLED.h>

void init_tulipas();
void handler_tulipas();

class tulipas_c {
    private:
    char numTulipa;

    public:
    char row;
    char col;
    CRGB* leds[4] = { NULL, NULL, NULL, NULL };

    void init(char _col, char _row, char _numTulipa);
    void setColor(CRGB color);

    //tulipas_c();
    //~tulipas_c();
};