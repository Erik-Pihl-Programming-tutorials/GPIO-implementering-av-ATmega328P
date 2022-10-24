/********************************************************************************
* header.h: Definitioner, deklarationer samt inkluderingsdirektiv för
*           GPIO-implementering med mikrodator ATmega328P.
*
*           Samtliga pinnar på Arduino Uno är ansluta till något av de tre
*           I/O-portarna B, C eller D:
*
*           Digitala pinnar 0 - 7 tillhör I/O-port D (PORTD0 - PORTD7).
*           Digitala pinnar 8 - 13 tillhör I/O-port B (PORTB0 - PORTD5).
*           Analoga pinnar A0 - A5 tillhör I/O-port C (PORTC0 - PORTC5).
*
*           Tre typer av register används för respektive I/O-port:
*
*           1. Datariktningsregister DDRB, DDRC samt DDRD används för att välja
*              datariktning för en given pin, där 1 = utport och 0 = inport.
*
*           2. Portregister PORTB, PORTC samt PORTD används för att skriva till
*              en given utport, där 1 = hög och 0 = låg. Dessa register används
*              också för att aktivera interna pullup-resistorer för inportar,
*              vilket görs för digitala inportar så att insignalen alltid blir
*              0 (låg) eller 1 (hög).
*
*           3. Pinregister PINB, PINC samt PIND används för att läsa av insignalen
*              från en given pin (normalt en inport), där 1 = hög och 0 = låg.
*
*           För att generera fördröjning används funktionen _delay_ms från
*           biblioteket util/delay.h, som tar emot fördröjningstiden i ms som
*           ett heltal. Innan detta bibliotek importeras måste mikrodatorns
*           klockfrekvens definieras via makrot F_CPU. 
*
*           Eftersom mikrodatorn i detta fall har en klockfrekvens på 16 MHz 
*           (via en oscillator på mikrokontrollerkortet Arduino Uno) sätts 
*           detta makro till ekvivalent med 16000000UL. UL indikerar att 
*           detta heltal sätts till datatypen unsigned long, vilket är ett
*           32-bitars osignerat (naturligt) heltal. 32-bitar är tillräckligt
*           stort för detta tal (en vanlig int är endast 16-bitar i detta system, 
*           vilket medför heltal mellan -32 768 till 32 767, alltså alldeles för 
*           lite för ett sådant stort tal. Genom att lägga till UL ser vi till 
*           att värdet på klockfrekvensen inte trunkeras (förkortas) till en 
*           reguljär int.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Mikrodatorns klockfrekvens (behövs för fördröjningsrutiner): */
#define F_CPU 16000000UL /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Innehåller information om olika I/O-register, såsom DDRB och PORTB. */
#include <util/delay.h> /* Innehåller fördröjningsrutiner, såsom _delay_ms. */

/* Makrodefinitioner: */
#define LED1 0 /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1 /* Lysdiod 2 ansluten till pin 9 / PORTB1. */
#define LED3 2 /* Lysdiod 3 ansluten till pin 10 / PORTB2. */

#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)   /* Tänder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3)   /* Tänder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Släcker lysdiod 3. */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     /* Tänder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Släcker lysdioderna. */

#define BUTTON1_IS_PRESSED (PINB &= (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_blink: Blinkar lysdioderna i en sekvens med angiven blinkhastighet.
*
*            - blink_speed_ms: Blinkhastigheten mätt i millisekunder.
********************************************************************************/
void led_blink(const uint16_t blink_speed_ms);

#endif /* HEADER_H_ */