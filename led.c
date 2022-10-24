#include "header.h"

/* Statiska funktioner: */
static void delay_ms(const uint16_t delay_time_ms);

/********************************************************************************
* led_blink: Blinkar lysdioderna i en sekvens med angiven blinkhastighet.
*
*            - blink_speed_ms: Blinkhastigheten mätt i millisekunder.
********************************************************************************/
void led_blink(const uint16_t blink_speed_ms)
{
   LED1_ON;
   LED2_OFF;
   LED3_OFF;
   delay_ms(blink_speed_ms);

   LED1_OFF;
   LED2_ON;
   LED3_OFF;
   delay_ms(blink_speed_ms);

   LED1_OFF;
   LED2_OFF;
   LED3_ON;
   delay_ms(blink_speed_ms);

   LED3_OFF;
   return;
}

/********************************************************************************
* delay_ms: Genererar fördröjning mätt i millisekunder.
*
*           - delay_time_ms: Angiven fördröjningstid.
********************************************************************************/
static void delay_ms(const uint16_t delay_time_ms)
{
   for (uint16_t i = 0; i < delay_time_ms; ++i) 
   {
      _delay_ms(1);
   }

   return;
}