#include <Arduino.h>

//#define OTA
#define TULIPAS

#ifdef OTA
#include "wifi.h"
#endif

#ifdef TULIPAS
#include "tuipas.h"
#endif

#include <FastLED.h>

#define R 15
#define G 12
#define B 13
#define BUILTIN_LED 2

void setup() {
    Serial.begin(115200);

    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(BUILTIN_LED, OUTPUT);

    digitalWrite(R, 0);
    digitalWrite(G, 0);
    digitalWrite(B, 0);
    digitalWrite(BUILTIN_LED, 0); // enciende con 0 wtf

#ifdef OTA
    init_wifi_configs();
#endif

#ifdef TULIPAS
    init_tulipas();
#endif
}


void loop() {
#ifdef TULIPAS
    handler_tulipas();
#endif

#ifdef OTA
    ota_handler();
#endif
}
