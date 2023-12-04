#include "tuipas.h"

#define DATA_PIN 5
#define NUM_LEDS 4
CRGB ledsArray[NUM_LEDS];

#define NUM_TULIPAS 34
tulipas_c tulipa[NUM_TULIPAS];

void tulipas_c::init(char _col, char _row, char _numTulipa) {
    row = _row;
    col = _col;
    numTulipa = _numTulipa;
    for(int i = 0; i < 4; i++) { leds[i] = &ledsArray[_numTulipa + i]; };
}

void tulipas_c::setColor(CRGB _color) {
    for(int i = 0; i < 4; i++) { *leds[i] = _color; }
}

void show_leds() {
    // FastLED.setBrightness(map(analogRead(0), 0, 1024, 0, 254));
    // FastLED.setBrightness(255);
    FastLED.show();
}

void init_tulipas() {
    pinMode(4, OUTPUT);
    FastLED.addLeds<WS2811, DATA_PIN, BRG>(ledsArray, NUM_LEDS);
    /*NO LEAS ESTO HARDCODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/

    // FILA 1
    tulipa[0].init(1, 1, 0);
    tulipa[1].init(1, 2, 1);
    tulipa[2].init(1, 3, 2);
    tulipa[3].init(1, 4, 3);
    tulipa[4].init(1, 5, 4);
    tulipa[5].init(1, 6, 5);
    tulipa[6].init(1, 7, 6);
    // FILA 2
    tulipa[7].init(2, 7, 7);
    tulipa[8].init(2, 6, 8);
    tulipa[9].init(2, 5, 9);
    tulipa[10].init(2, 1, 10);
    // FILA 3
    tulipa[11].init(3, 1, 11);
    tulipa[12].init(3, 5, 12);
    tulipa[13].init(3, 6, 13);
    tulipa[14].init(3, 7, 14);
    // FILA 4
    tulipa[15].init(4, 7, 15);
    tulipa[16].init(4, 6, 16);
    tulipa[17].init(4, 5, 17);
    tulipa[18].init(4, 1, 18);
    // FILA 5
    tulipa[19].init(5, 1, 19);
    tulipa[20].init(5, 5, 20);
    tulipa[21].init(5, 6, 21);
    tulipa[22].init(5, 7, 22);
    // FILA 6
    tulipa[23].init(6, 7, 23);
    tulipa[24].init(6, 6, 24);
    tulipa[25].init(6, 5, 25);
    tulipa[26].init(6, 1, 26);
    // FILA 7
    tulipa[27].init(7, 1, 27);
    tulipa[28].init(7, 2, 28);
    tulipa[29].init(7, 3, 29);
    tulipa[30].init(7, 4, 30);
    tulipa[31].init(7, 5, 31);
    tulipa[32].init(7, 6, 32);
    tulipa[33].init(7, 7, 33);

    //for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CRGB::Black); }
    // tulipa[0].setColor(CRGB::Black);
    // FastLED.show();
    Serial.print("HOLA???");
}

long counter = 0;
long counterBefore = 0;

void handler_tulipas() {
    counter = millis() - counterBefore;

    if(counter < 1000) {
       ledsArray[0] = CRGB::Blue;
    }

    if(counter > 2000 && counter < 1000) { ledsArray[0] = CRGB::Red; }

    if(counter > 3000) { counterBefore = millis(); }
    FastLED.show();
    Serial.println(counter);
    delay(10);
}