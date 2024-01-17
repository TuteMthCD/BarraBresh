#include "tulipas.h"
#include "button.h"

#include "banderas.h"

#define DATA_PIN 4
#define PIXELPTULIPA 4
#define NUM_TULIPAS 34
#define LIMIT_ROW 7
#define LIMIT_COL 7

unsigned short whiteCounter = 0, yellowCounter = 0, greenCounter = 0, blueCounter = 0;
unsigned short selectEfect = 0;

Button white(BUTTON_WHITE), yellow(BUTTON_YELLOW), green(BUTTON_GREEN), blue(BUTTON_BLUE);

CRGB ArrayLeds[PIXELPTULIPA * NUM_TULIPAS];
CRGB Color1, Color2, Color3, Color4;

tulipas_c* getTulipa(int, int);

void tulipas_c::init(uint8_t _col, uint8_t _row, uint8_t _pos) {
    col = _col;
    row = _row;
    pos = _pos;
    firstLed = pos * PIXELPTULIPA;

    for(int i = 0; i < PIXELPTULIPA; i++) { leds[i] = &ArrayLeds[firstLed + i]; }
}
void tulipas_c::setColor(CRGB color) {
    for(int i = 0; i < PIXELPTULIPA; i++) { *leds[i] = color; }
}

tulipas_c tulipa[NUM_TULIPAS];

void init_tulipas() {
    pinMode(DATA_PIN, OUTPUT);
    FastLED.addLeds<WS2811, DATA_PIN, BRG>(ArrayLeds, PIXELPTULIPA * NUM_TULIPAS);
    // COL - ROW - LED
    tulipa[0].init(1, 7, 0);
    tulipa[1].init(1, 6, 1);
    tulipa[2].init(1, 5, 2);
    tulipa[3].init(1, 4, 3);
    tulipa[4].init(1, 3, 4);
    tulipa[5].init(1, 2, 5);
    tulipa[6].init(1, 1, 6);
    tulipa[7].init(2, 1, 7);
    tulipa[8].init(3, 1, 8);
    tulipa[9].init(4, 1, 9);
    tulipa[10].init(5, 1, 10);
    tulipa[11].init(6, 1, 11);
    tulipa[12].init(7, 1, 12);
    tulipa[13].init(7, 2, 13);
    tulipa[14].init(7, 3, 14);
    tulipa[15].init(7, 4, 15);
    tulipa[16].init(7, 5, 16);
    tulipa[17].init(7, 6, 17);
    tulipa[18].init(7, 7, 18);
    tulipa[19].init(6, 7, 19);
    tulipa[20].init(6, 6, 20);
    tulipa[21].init(6, 5, 21);
    tulipa[22].init(5, 7, 22);
    tulipa[23].init(5, 6, 23);
    tulipa[24].init(5, 5, 24);
    tulipa[25].init(4, 7, 25);
    tulipa[26].init(4, 6, 26);
    tulipa[27].init(4, 5, 27);
    tulipa[28].init(3, 7, 28);
    tulipa[29].init(3, 6, 29);
    tulipa[30].init(3, 5, 30);
    tulipa[31].init(2, 7, 31);
    tulipa[32].init(2, 6, 32);
    tulipa[33].init(2, 5, 33);


    for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CRGB::Black); }
    yellow.onPress([] {
        if(selectEfect == 1) {
            if(yellowCounter < 5) {
                yellowCounter++;
            } else
                yellowCounter = 0;
        } else {
            selectEfect = 1;
            yellowCounter = 0;
        }
        switch(yellowCounter) {
        case 0:
            Color1 = CRGB::Cyan;
            Color2 = CRGB::Blue;
            break;

        case 1:
            Color1 = CRGB::Red;
            Color2 = CRGB::White;
            break;

        case 2:
            Color1 = CRGB::Purple;
            Color2 = CRGB::Cyan;
            break;
        case 3:
            Color1 = CRGB::Green;
            Color2 = CRGB::White;
            break;
        case 4:
            Color1 = CRGB::Orange;
            Color2 = CRGB::Red;
            break;
        }
    });
    green.onPress([] {
        if(selectEfect != 2) {
            selectEfect = 2;
            greenCounter = 0;
        } else if(greenCounter < 2)
            greenCounter++;
        else
            greenCounter = 0;
        // greenCounter = 1;
    });
    white.onPress([] { selectEfect = 3; });
    blue.onPress([] {
        if(selectEfect != 4) {
            selectEfect = 4;
            blueCounter = 0;
        } else if(blueCounter < 10) {
            blueCounter++;
        } else
            blueCounter = 0;
    });
}

int offset = 0;

bool button_W = false, button_B = false, button_Y = false, button_G = false;

tulipas_c* getTulipa(int _col, int _row) {
    for(int i = 0; i < NUM_TULIPAS; i++) {
        if(tulipa[i].row == _row && tulipa[i].col == _col) { return &tulipa[i]; }
    }
    return NULL;
}

unsigned long timeBefore = 0, secondTimeBefore = 0;
#define STEP_FUNDIDO 3    // siempre numeros impares
#define TIME_FUNDIDO 5000 // en MS

void handle_tulipas() {
    switch(selectEfect) {
    case 1:
        if(millis() - timeBefore > 100) {
            for(int i = 0; i < NUM_TULIPAS; i++) tulipa[i].setColor(Color1);

            timeBefore = millis();
            static int i, j;

            tulipas_c* p;

            (p = getTulipa(i, j)) != NULL ? p->setColor(Color2) : void();
            (p = getTulipa(i - 1, j)) != NULL ? p->setColor(Color2) : void();
            (p = getTulipa(i - 2, j)) != NULL ? p->setColor(Color2) : void();

            if(i < LIMIT_COL) {
                i++;
            } else {
                i = 0;
                if(j < LIMIT_COL) {
                    j++;
                } else {
                    j = 0;
                    i = 0;
                }
            }
        }
        break;
    case 2:
        tulipas_c* p;
        switch(greenCounter) {
        case 0:
            static int counterTarget = 0;

            if(millis() - secondTimeBefore > TIME_FUNDIDO) {
                secondTimeBefore = millis();
                counterTarget += 1;
            }

            if(millis() - timeBefore > 5) {
                timeBefore = millis();
                for(int COL = 0; COL < LIMIT_COL; COL++) {
                    for(int ROW = 0; ROW < LIMIT_ROW; ROW++) {
                        if((p = getTulipa(COL + 1, ROW + 1)) != NULL) {

                            CRGB curr = *(p->leds[0]);
                            CRGB target = CRGB::Black;

                            switch(counterTarget) {
                            case 0: target = lgbt[ROW][COL]; break;
                            case 1: target = CRGB::Cyan; break;
                            case 2: target = trans[ROW][COL]; break;
                            case 3: target = CRGB::Fuchsia; break;

                            default: counterTarget = 0; break;
                            }

                            if(curr != target) {
                                if(curr.red != target.red)
                                    curr.red > target.red ? curr.red -= STEP_FUNDIDO : curr.red += STEP_FUNDIDO;
                                if(curr.green != target.green)
                                    curr.green > target.green ? curr.green -= STEP_FUNDIDO : curr.green += STEP_FUNDIDO;
                                if(curr.blue != target.blue)
                                    curr.blue > target.blue ? curr.blue -= STEP_FUNDIDO : curr.blue += STEP_FUNDIDO;
                            }

                            p->setColor(curr);
                        }
                    }
                }
            }
            break;
        case 1:
            for(int COL = 0; COL < LIMIT_COL; COL++) {
                for(int ROW = 0; ROW < LIMIT_ROW; ROW++) {
                    (p = getTulipa(COL + 1, ROW + 1)) != NULL ? p->setColor(lgbt[ROW][COL]) : void();
                }
            }
            break;
        case 2:
            for(int COL = 0; COL < LIMIT_COL; COL++) {
                for(int ROW = 0; ROW < LIMIT_ROW; ROW++) {
                    (p = getTulipa(COL + 1, ROW + 1)) != NULL ? p->setColor(trans[ROW][COL]) : void();
                }
            }
            break;
        default: greenCounter = 0;
        }
        break;
    case 3:
        for(int i = 0; i < NUM_TULIPAS; i++) { tulipa[i].setColor(CHSV((millis() / 35) % 255, 255, 255)); }
        break;
    case 4:
        for(int i = 0; i < NUM_TULIPAS; i++) {
            CRGB color = CHSV((int)25.5 * blueCounter % 255, 255, 255);
            tulipa[i].setColor(color);
        }
        break;

    default:
        Serial.println("error Efect, go to efect 1");
        selectEfect = 1;
        break;
    }

    // handler botones
    blue.handle();
    white.handle();
    green.handle();
    yellow.handle();

    FastLED.show(map(analogRead(0), 0, 1023, 0, 255));
    delay(10);
}