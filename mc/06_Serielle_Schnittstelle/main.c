// Sendet einen Gruss und schickt jedes empfangene Zeichen um 1 erhoeht zurueck
// (a -> b). Terminal: 9600 Baud, 8N1 (USB-Seriell des Nano, COM4).

#include <avr/io.h>
#include "serial.h"

int main(void)
{
    serial_init();
    serial_send_string("Hallo Welt\r\n");
    serial_send_integer(42);
    serial_send_string("\r\n");
    serial_send_double(3.14);
    serial_send_string("\r\n");

    while (1) {
        uint8_t value = serial_receive();
        serial_send(value + 1);
    }
}
