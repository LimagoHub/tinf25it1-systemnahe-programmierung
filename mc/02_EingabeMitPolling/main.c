// Eingabe per Polling: Taster an PD2 (D2) schaltet die LED an PB5 (D13) ein,
// Taster an PD3 (D3) aus. Taster gegen GND, interne Pull-ups aktiv.

#include <avr/io.h>

int main(void)
{
    DDRB |= (1 << DDB5);                    // PB5 = Ausgang (LED)
    PORTB &= ~(1 << PORTB5);
    DDRD &= ~((1 << DDD2) | (1 << DDD3));   // PD2, PD3 = Eingang
    PORTD |= (1 << PORTD2) | (1 << PORTD3); // Pull-ups an

    while (1) {
        if (!(PIND & (1 << PIND2)))
            PORTB |= (1 << PORTB5);
        if (!(PIND & (1 << PIND3)))
            PORTB &= ~(1 << PORTB5);
    }
}
