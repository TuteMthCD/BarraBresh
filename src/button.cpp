#include "button.h"

#define TIMER_FASTPRESED 300

Button::Button(unsigned char _pin) {
    pin = _pin;
    pinMode(_pin, INPUT_PULLUP);
}

void Button::handle() {
    bool button = !digitalRead(pin);

    if(button) {
        if(!pressed) {
            timeInit = millis();
            pressed = true;
            if(p_onFalling != NULL)
                p_onFalling(); // onfalling se puede llegar a ejecuar 2 a 3 veces
        }
    } else {
        if(pressed) {
            timePressed = millis() - timeInit;
            pressed = false;
            if(p_onRelease != NULL) p_onRelease();
        }
    }
    if(timePressed > 5 && timePressed != 0) {
        if(timePressed <= TIMER_FASTPRESED) {
            if(p_onPress != NULL) p_onPress();
        } else if(timePressed > TIMER_FASTPRESED) {
            if(p_onLongPress != NULL) {
                p_onLongPress();
            } else if(p_onPress != NULL) p_onPress();
        }
        timePressed = 0;
    }
}

void Button::onFalling(void (*_ptrFnt)()) {
    p_onFalling = _ptrFnt;
}

void Button::onPress(void (*_ptrFnt)()) {
    p_onPress = _ptrFnt;
}

void Button::onRelease(void (*_ptrFnt)()) {
    p_onRelease = _ptrFnt;
}

void Button::onLongPress(void (*_ptrFnt)()) {
    p_onLongPress = _ptrFnt;
}

unsigned int Button::getTimePressed() {
    return timePressed;
}