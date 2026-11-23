// Analoger Eingang, Variante OHNE ATOMIC_BLOCK.
// ADC0 (Nano: A0) laeuft im Free-Running-Modus, der Wert wird bei jeder
// Aenderung per USART ausgegeben (9600 Baud). Empfangene Zeichen kommen als Echo zurueck.
//
// Sicherer Zugriff auf den 16-Bit-Wert ohne Interrupts zu sperren:
// Die ISR zaehlt einen 8-Bit-Sequenzzaehler vor und nach dem Schreiben hoch.
// (Ein 8-Bit-Zugriff ist auf dem AVR von Natur aus unteilbar.)
// main liest den Wert und wiederholt das Lesen, wenn der Zaehler waehrenddessen
// ungerade war (ISR mitten im Schreiben) oder sich geaendert hat.

#include <stdlib.h>
#include "usart.h"

static volatile uint16_t analogwert = 0;
static volatile uint8_t  sequenz = 0;

ISR(USART_RX_vect)
{
    usart_send(UDR0);
}

ISR(ADC_vect)
{
    sequenz++;                  // ungerade: Schreiben laeuft
    analogwert = ADC;
    sequenz++;                  // gerade: Wert ist gueltig
}

static uint16_t analogwert_lesen(void)
{
    uint16_t wert;
    uint8_t  s1, s2;

    do {
        s1   = sequenz;
        wert = analogwert;
        s2   = sequenz;
    } while ((s1 != s2) || (s1 & 1));

    return wert;
}

static void init(void)
{
    usart_init();
    usart_send_string("Hallo Terminal\r\n");

    ADMUX  = (1 << REFS0);                      // Referenz AVcc, Kanal 0
    ADCSRA = (1 << ADEN) | (1 << ADATE) | (1 << ADIE)
           | (1 << ADPS2) | (1 << ADPS0)        // Prescaler 32
           | (1 << ADSC);                       // Free Running starten

    sei();
}

int main(void)
{
    uint16_t analogwert_alt = 0;
    char buffer[8];

    init();

    while (1) {
        uint16_t wert = analogwert_lesen();

        if (wert != analogwert_alt) {
            analogwert_alt = wert;
            itoa(wert, buffer, 10);
            usart_send_string(buffer);
            usart_send_string("\r\n");
        }
    }
}
