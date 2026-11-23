// Blink: LED auf PB5 (Nano: D13) blinkt im Sekundentakt.
// F_CPU kommt aus dem Makefile.

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << DDB5);                // PB5 wird zum Ausgang

    while (1) {
        PORTB |= (1 << PORTB5);
        _delay_ms(500);
        PORTB &= ~(1 << PORTB5);
        _delay_ms(500);
    }
}
