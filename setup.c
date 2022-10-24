/********************************************************************************
* setup.c: Innehåller initieringsrutiner för mikrodatorn.
********************************************************************************/
#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar. Lysdiodernas pinnar 9 - 10 sätts
*        till utportar, medan den interna pullup-resistorn på tryckknappens
*        pin 13 aktiveras för att insignalen alltid skall bli hög eller låg.
********************************************************************************/
void setup(void)
{
   DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
   PORTB = (1 << BUTTON1);
   return;
}