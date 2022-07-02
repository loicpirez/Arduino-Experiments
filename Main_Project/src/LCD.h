#ifndef H_LCD
#define H_LCD

#include <LiquidCrystal.h>

// void lcdInit(LiquidCrystal lcd, char *message);
// void lcdDrawLine(LiquidCrystal lcd, char *message);
// void lcdClearLine(LiquidCrystal lcd, int line);

class LCD
{
private:
    LiquidCrystal *lcd;

public:
    LCD(uint8_t rs, uint8_t e, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    init(char *message);
    lcdClearLine(int line);
    lcdDrawLine(char *message);
};

#endif