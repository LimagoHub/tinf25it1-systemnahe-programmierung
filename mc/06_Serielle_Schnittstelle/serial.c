#include "serial.h"

static volatile fptr mycallback;

void serial_init(fptr callback)
{
    mycallback = callback;
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Empfaenger und Sender an
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
    // 8 Datenbits, 1 Stopbit
    UCSR0B |= (1 << RXCIE0);
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


ISR (USART_RX_vect)
{
    mycallback(UDR0);
}