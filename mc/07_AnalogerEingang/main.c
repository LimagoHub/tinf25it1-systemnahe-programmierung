// Analoger Eingang: ADC0 (Nano: A0) laeuft im Free-Running-Modus, der Wert
// wird bei jeder Aenderung per USART ausgegeben (9600 Baud). Empfangene
// Zeichen werden als Echo zurueckgeschickt.

#include <stdlib.h>
#include <util/atomic.h>
#include "usart.h"

static volatile uint16_t analogwert = 0;

ISR(USART_RX_vect)
{
    usart_send(UDR0);
}

ISR(ADC_vect)
{
    analogwert = ADC;
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
        uint16_t wert;
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            wert = analogwert;
        }

        if (wert != analogwert_alt) {
            analogwert_alt = wert;
            itoa(wert, buffer, 10);
            usart_send_string(buffer);
            usart_send_string("\r\n");
        }
    }
}
