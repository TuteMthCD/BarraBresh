#include <Arduino.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

//#define SSID "Fibertel WiFi528 2.4GHz"
//#define PSK "Jm_23242526"

#define SSID "Telecentro-7708"
#define PSK "TNYMWWQWZ2Q2"

void init_wifi_configs() {
    // Conectar a WiFi
    WiFi.begin(SSID, PSK);
    while(WiFi.status() != WL_CONNECTED) {
        delay(250);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conexión WiFi establecida");
    Serial.println(WiFi.localIP());

    // Configurar OTA
    ArduinoOTA.onStart([]() { Serial.println("Iniciando actualización"); });
    ArduinoOTA.onEnd([]() { Serial.println("\nActualización completada"); });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error durante la actualización[%u]: ", error);
        if(error == OTA_AUTH_ERROR)
            Serial.println("Error de autenticación");
        else if(error == OTA_BEGIN_ERROR)
            Serial.println("Error de inicio");
        else if(error == OTA_CONNECT_ERROR)
            Serial.println("Error de conexión");
        else if(error == OTA_RECEIVE_ERROR)
            Serial.println("Error de recepción");
        else if(error == OTA_END_ERROR)
            Serial.println("Error de finalización");
    });
    ArduinoOTA.begin();

    // Configurar mDNS
    String MDNSName = "ESP"; //+ String(ESP.getChipId());
    if(MDNS.begin(MDNSName)) {
        Serial.println("MDNS responder started");
        Serial.println(MDNSName);
    }
    // MDNS.addService("esp", "tcp", 80);
}

void ota_handler() {
    ArduinoOTA.handle();
    MDNS.update();
}