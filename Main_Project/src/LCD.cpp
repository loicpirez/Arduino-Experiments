#include "LCD.h"

LCD::LCD(uint8_t rs, uint8_t e, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  lcd = new LiquidCrystal(rs, e, d4, d5, d6, d7);
}

LCD::init(char *message)
{
  this->lcd->begin(16, 2);
  this->lcd->print(message);
}

LCD::lcdClearLine(int line)
{
  this->lcd->setCursor(0, line);
  for (int n = 0; n < 16; n++)
  {
    this->lcd->print(" ");
  }
}

LCD::lcdDrawLine(char *message)
{
  this->lcdClearLine(1);
  this->lcd->setCursor(0, 1);
  this->lcd->print(message);
}