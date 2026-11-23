#include "serial.h"

void serial_init(void)
{
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Empfaenger und Sender an
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // 8 Datenbits, 1 Stopbit
}

void serial_send(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}

uint8_t serial_receive(void)
{
    while (!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}

void serial_send_string(const char *textToSend)
{
    while (*textToSend)
        serial_send((uint8_t)*textToSend++);
}

void serial_send_integer(int16_t numberToSend)
{
    char buffer[8];
    itoa(numberToSend, buffer, 10);
    serial_send_string(buffer);
}

void serial_send_double(double numberToSend)
{
    char buffer[16];
    dtostrf(numberToSend, 4, 2, buffer);
    serial_send_string(buffer);
}
