// Externe Interrupts: Taster an PD2 (INT0) / PD3 (INT1), Pegelwechsel loest aus.
// INT0 -> PORTB = 0x00, INT1 -> PORTB = 0xFF (LED an PB5 = D13 ist dabei mit dran).

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
    PORTB = 0x00;
}

ISR(INT1_vect)
{
    PORTB = 0xFF;
}

int main(void)
{
    DDRB  = 0xFF;
    PORTB = 0xFF;

    DDRD  &= ~((1 << DDD2) | (1 << DDD3));      // PD2, PD3 = Eingang
    PORTD |= (1 << PORTD2) | (1 << PORTD3);     // Pull-ups an

    EICRA |= (1 << ISC00) | (1 << ISC10);       // INT0/INT1: jede Aenderung
    EIMSK |= (1 << INT0) | (1 << INT1);
    sei();

    while (1) {
    }
}
