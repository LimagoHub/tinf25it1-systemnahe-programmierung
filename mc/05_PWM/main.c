// Fast-PWM mit Timer0 an OC0A = PD6 (Nano: D6), Helligkeit faedelt auf und ab.
// PWM-Frequenz = F_CPU / (1024 * 256) = ca. 61 Hz bei 16 MHz (Prescaler 1024).

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    int8_t richtung = 1;

    DDRD |= (1 << DDD6);
    OCR0A = 64;

    TCCR0A |= (1 << COM0A1);                    // nicht invertierend
    TCCR0A |= (1 << WGM01) | (1 << WGM00);      // Fast PWM
    TCCR0B |= (1 << CS02) | (1 << CS00);        // Prescaler 1024

    while (1) {
        if (OCR0A == 255 || OCR0A == 0)
            richtung = -richtung;
        _delay_ms(10);
        OCR0A += richtung;
    }
}
