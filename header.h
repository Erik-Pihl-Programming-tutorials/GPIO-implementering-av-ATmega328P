/********************************************************************************
* header.h: Definitioner, deklarationer samt inkluderingsdirektiv f�r
*           GPIO-implementering med mikrodator ATmega328P.
*
*           Samtliga pinnar p� Arduino Uno �r ansluta till n�got av de tre
*           I/O-portarna B, C eller D:
*
*           Digitala pinnar 0 - 7 tillh�r I/O-port D (PORTD0 - PORTD7).
*           Digitala pinnar 8 - 13 tillh�r I/O-port B (PORTB0 - PORTD5).
*           Analoga pinnar A0 - A5 tillh�r I/O-port C (PORTC0 - PORTC5).
*
*           Tre typer av register anv�nds f�r respektive I/O-port:
*
*           1. Datariktningsregister DDRB, DDRC samt DDRD anv�nds f�r att v�lja
*              datariktning f�r en given pin, d�r 1 = utport och 0 = inport.
*
*           2. Portregister PORTB, PORTC samt PORTD anv�nds f�r att skriva till
*              en given utport, d�r 1 = h�g och 0 = l�g. Dessa register anv�nds
*              ocks� f�r att aktivera interna pullup-resistorer f�r inportar,
*              vilket g�rs f�r digitala inportar s� att insignalen alltid blir
*              0 (l�g) eller 1 (h�g).
*
*           3. Pinregister PINB, PINC samt PIND anv�nds f�r att l�sa av insignalen
*              fr�n en given pin (normalt en inport), d�r 1 = h�g och 0 = l�g.
*
*           F�r att generera f�rdr�jning anv�nds funktionen _delay_ms fr�n
*           biblioteket util/delay.h, som tar emot f�rdr�jningstiden i ms som
*           ett heltal. Innan detta bibliotek importeras m�ste mikrodatorns
*           klockfrekvens definieras via makrot F_CPU. 
*
*           Eftersom mikrodatorn i detta fall har en klockfrekvens p� 16 MHz 
*           (via en oscillator p� mikrokontrollerkortet Arduino Uno) s�tts 
*           detta makro till ekvivalent med 16000000UL. UL indikerar att 
*           detta heltal s�tts till datatypen unsigned long, vilket �r ett
*           32-bitars osignerat (naturligt) heltal. 32-bitar �r tillr�ckligt
*           stort f�r detta tal (en vanlig int �r endast 16-bitar i detta system, 
*           vilket medf�r heltal mellan -32 768 till 32 767, allts� alldeles f�r 
*           lite f�r ett s�dant stort tal. Genom att l�gga till UL ser vi till 
*           att v�rdet p� klockfrekvensen inte trunkeras (f�rkortas) till en 
*           regulj�r int.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Mikrodatorns klockfrekvens (beh�vs f�r f�rdr�jningsrutiner): */
#define F_CPU 16000000UL /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inneh�ller information om olika I/O-register, s�som DDRB och PORTB. */
#include <util/delay.h> /* Inneh�ller f�rdr�jningsrutiner, s�som _delay_ms. */

/* Makrodefinitioner: */
#define LED1 0 /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1 /* Lysdiod 2 ansluten till pin 9 / PORTB1. */
#define LED3 2 /* Lysdiod 3 ansluten till pin 10 / PORTB2. */

#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1)   /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)   /* T�nder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3)   /* T�nder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Sl�cker lysdiod 3. */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Sl�cker lysdioderna. */

#define BUTTON1_IS_PRESSED (PINB &= (1 << BUTTON1)) /* Indikerar nedtryckning av tryckknapp 1. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar.
********************************************************************************/
void setup(void);

/********************************************************************************
* led_blink: Blinkar lysdioderna i en sekvens med angiven blinkhastighet.
*
*            - blink_speed_ms: Blinkhastigheten m�tt i millisekunder.
********************************************************************************/
void led_blink(const uint16_t blink_speed_ms);

#endif /* HEADER_H_ */