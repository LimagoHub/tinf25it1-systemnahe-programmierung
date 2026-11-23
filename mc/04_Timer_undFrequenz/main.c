// Timer0 im CTC-Modus, Prescaler 256: Compare-Match-ISR kippt PORTB.
// Toggle-Frequenz = F_CPU / 256 / (OCR0A + 1); bei 16 MHz und OCR0A = 70
// sind das 880 Hz -> 440 Hz Rechteck (Kammerton A) an jedem Pin von PORTB.

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect)
{
    PORTB = ~PORTB;
}

int main(void)
{
    DDRB  = 0xFF;
    PORTB = 0;

    TCCR0A |= (1 << WGM01);         // CTC
    OCR0A   = 70;                   // A (440 Hz); 117 -> ca. 265 Hz (C)
    TIMSK0 |= (1 << OCIE0A);
    sei();

    TCCR0B |= (1 << CS02);          // Prescaler 256, Timer startet

    while (1) {
    }
}
