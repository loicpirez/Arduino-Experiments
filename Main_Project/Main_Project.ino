#include "IRremote.h"
#include "src/LCD.h"


LCD* lcd = new LCD(7, 8, 9, 10, 11, 12);

// IR
// TODO: Faire une class avec systeme de callback
//       Enum avec IDs
int receiver = 2;
IRrecv irrecv(receiver);
decode_results results;
void translateIR() 
{
  switch(results.value)
  {
    case 0xFFA25D: lcd->lcdDrawLine("BTN POWER"); break;
    case 0xFFE21D: lcd->lcdDrawLine("BTN FUNC/STOP"); break;
    case 0xFF629D: lcd->lcdDrawLine("BTN VOL+"); break;
    case 0xFF22DD: lcd->lcdDrawLine("BTN FAST BACK");    break;
    case 0xFF02FD: lcd->lcdDrawLine("BTN PAUSE");    break;
    case 0xFFC23D: lcd->lcdDrawLine("BTN FAST FORWARD");   break;
    case 0xFFE01F: lcd->lcdDrawLine("BTN DOWN");    break;
    case 0xFFA857: lcd->lcdDrawLine("BTN VOL-");    break;
    case 0xFF906F: lcd->lcdDrawLine("BTN UP");    break;
    case 0xFF9867: lcd->lcdDrawLine("BTN EQ");    break;
    case 0xFFB04F: lcd->lcdDrawLine("BTN ST/REPT");    break;
    case 0xFF6897: lcd->lcdDrawLine("Channel 0");    break;
    case 0xFF30CF: lcd->lcdDrawLine("Channel 1");    break;
    case 0xFF18E7: lcd->lcdDrawLine("Channel 2");    break;
    case 0xFF7A85: lcd->lcdDrawLine("Channel 3");    break;
    case 0xFF10EF: lcd->lcdDrawLine("Channel 4");    break;
    case 0xFF38C7: lcd->lcdDrawLine("Channel 5");    break;
    case 0xFF5AA5: lcd->lcdDrawLine("Channel 6");    break;
    case 0xFF42BD: lcd->lcdDrawLine("Channel 7");    break;
    case 0xFF4AB5: lcd->lcdDrawLine("Channel 8");    break;
    case 0xFF52AD: lcd->lcdDrawLine("Channel 9");    break;
  }
  delay(500);
}
// IR

void setup()
{
  lcd->init("IR Receiver");
  irrecv.enableIRIn();
}


void loop() {
  if (irrecv.decode(&results)) 
  {
    translateIR(); 
    irrecv.resume(); 
  }  
}
