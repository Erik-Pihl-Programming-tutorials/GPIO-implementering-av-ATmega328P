/********************************************************************************
* main.c: Demonstration av enkel GPIO-implementering för mikrodator ATmega328P.
*         Programkod är skrivet i C via Microchip Studio 7.0.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar mikrodatorn vid start. Vid nedtryckning av tryckknappen
*       ansluten till pin 13 / PORTB5 så blinkar lysdioderna anslutna till
*       pin 8 - 10 / PORTB0 - PORTB2 i en slinga var 100:e millisekund,
*       annars hålls de släckta.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
      if (BUTTON1_IS_PRESSED)
      {
         led_blink(100);
      }
      else
      {
         LEDS_OFF;
      }
   }

   return 0;
}

