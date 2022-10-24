# GPIO-implementering-av-ATmega328P
Demonstration av GPIO-implementering för digitala in- och utportar i C för mikrodator ATmega328P.
Tre lysdioder anslutna till pin 8 - 10 / PORTB0 - PORTB2 sätts till att blinka var 100:e millisekund vid nedtryckning av
en tryckknapp ansluten till pin 13 / PORTB5.

Filen header.h innehåller inkluderingsdirektiv, makron och funktionsdeklarationer för implementering av det inbyggda systemet.

I filen main.c initieras det inbyggda systemet, följt av att nedtryckning av tryckknappen medför att lysdioderna blinkar i en
sekvens var 100:e millisekunder. Övrig tid hålls de släckta.

Filen setup.c innehåller funktioner för initiering av det inbyggda systemet.

Filen led.c innehåller en blinkrutin för lysdioder, som blinkar i en slinga med valbar blinkhastighet.

Se video tutorial här:
https://youtu.be/AOppJnKmfLY
