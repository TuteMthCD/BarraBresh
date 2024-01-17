#include <Arduino.h>

class Button {
    public:
    Button(unsigned char);
    void handle(void);
    void onFalling(void (*ptrFnt)());
    void onPress(void (*ptrFnt)());
    void onRelease(void (*ptrFnt)());
    void onLongPress(void (*ptrFnt)());
    unsigned int getTimePressed(void);


    private:
    unsigned int timePressed = 0;
    unsigned int timeInit = 0;
    bool pressed = false;
    unsigned char pin;
    void (*p_onFalling)();
    void (*p_onPress)();
    void (*p_onRelease)();
    void (*p_onLongPress)();
};