// Sendet einen Gruss und schickt jedes empfangene Zeichen um 1 erhoeht zurueck
// (a -> b). Terminal: 9600 Baud, 8N1 (USB-Seriell des Nano, COM4).

#include <avr/io.h>


#include "serial.h"


void doSomething(uint8_t receivedValue) {
    serial_send(receivedValue + 1);
}



int main(void) {
    serial_init(doSomething);
    sei();
    while (1) {

    }


}
