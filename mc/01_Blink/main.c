#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(BYTE,BIT) (BYTE |= (1 << BIT))
#define CLEAR_BIT(BYTE,BIT) (BYTE &= ~(1 << BIT))
#define TOGGLE_BIT(BYTE,BIT) (BYTE ^= (1 << BIT))
#define GET_BIT(BYTE,BIT) (BYTE & (1 << BIT))

int main(void)
{
    SET_BIT(DDRB,DD5) ;// Data Direction Register B
    while (1) {

           TOGGLE_BIT(PORTB,PB5) ;/* LED an */
            _delay_ms(100);



    }
}
