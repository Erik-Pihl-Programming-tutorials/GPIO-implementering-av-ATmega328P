/********************************************************************************
* setup.c: Inneh�ller initieringsrutiner f�r mikrodatorn.
********************************************************************************/
#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar. Lysdiodernas pinnar 9 - 10 s�tts
*        till utportar, medan den interna pullup-resistorn p� tryckknappens
*        pin 13 aktiveras f�r att insignalen alltid skall bli h�g eller l�g.
********************************************************************************/
void setup(void)
{
   DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
   PORTB = (1 << BUTTON1);
   return;
}