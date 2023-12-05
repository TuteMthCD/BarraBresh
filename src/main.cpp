#include <Arduino.h>

#include "tulipas.h"

#define BUILTIN_LED 2

bool stat = false;

void setup() {
    Serial.begin(115200);

    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, 0); // enciende con 0 wtf
    
   //pinMode(BUTTON_WHITE,INPUT_PULLUP);
    pinMode(BUTTON_YELLOW,INPUT_PULLUP);
    pinMode(BUTTON_GREEN,INPUT_PULLUP);
    pinMode(BUTTON_BLUE,INPUT_PULLUP);

    init_tulipas();
}

void loop() {
    stat = !stat;
    digitalWrite(BUILTIN_LED, stat);
    handle_tulipas();
}