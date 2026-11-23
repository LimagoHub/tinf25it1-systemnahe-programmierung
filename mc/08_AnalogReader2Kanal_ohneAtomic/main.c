// Analog-Reader fuer 2 Kanaele (ADC0 = A0, ADC1 = A1 am Nano), Variante OHNE ATOMIC_BLOCK.
// Die Wandlung laeuft komplett im ADC-Interrupt: die ISR speichert den Wert
// des aktuellen Kanals, schaltet den Multiplexer auf den naechsten Kanal um und
// startet die naechste Wandlung. Die Hauptschleife gibt alle 250 ms
// beide Werte per USART aus (9600 Baud).
//
// Sicherer Zugriff auf die 16-Bit-Werte ohne Interrupts zu sperren:
// Die ISR zaehlt einen 8-Bit-Sequenzzaehler vor und nach dem Schreiben hoch
// (ein 8-Bit-Zugriff ist auf dem AVR unteilbar). main wiederholt das Lesen,
// wenn der Zaehler ungerade war oder sich waehrenddessen geaendert hat.

#include <stdint.h>
#include <util/delay.h>
#include "usart.h"

#define ADC_CHANNELS 2

static volatile uint16_t adc_werte[ADC_CHANNELS];
static volatile uint8_t  adc_kanal = 0;
static volatile uint8_t  sequenz = 0;

ISR(ADC_vect)
{
    sequenz++;                                  // ungerade: Schreiben laeuft
    adc_werte[adc_kanal] = ADC;
    sequenz++;                                  // gerade: Werte sind gueltig

    adc_kanal = (uint8_t)((adc_kanal + 1) % ADC_CHANNELS);
    ADMUX = (ADMUX & 0xF0) | adc_kanal;         // naechster Kanal
    ADCSRA |= (1 << ADSC);                      // naechste Wandlung starten
}

static void adc_init(void)
{
    ADMUX  = (1 << REFS0);                      // Referenz AVcc, Kanal 0
    ADCSRA = (1 << ADEN) | (1 << ADIE)
           | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // Prescaler 128 (125 kHz)
    ADCSRA |= (1 << ADSC);                      // erste Wandlung starten
}

static uint16_t adc_lesen(uint8_t kanal)
{
    uint16_t wert;
    uint8_t  s1, s2;

    do {
        s1   = sequenz;
        wert = adc_werte[kanal];
        s2   = sequenz;
    } while ((s1 != s2) || (s1 & 1));

    return wert;
}

int main(void)
{
    usart_init();
    usart_send_string("Analog-Reader 2 Kanaele\r\n");

    adc_init();
    sei();

    while (1) {
        usart_send_string("A0=");
        usart_send_uint16(adc_lesen(0));
        usart_send_string("  A1=");
        usart_send_uint16(adc_lesen(1));
        usart_send_string("\r\n");
        _delay_ms(250);
    }
}
