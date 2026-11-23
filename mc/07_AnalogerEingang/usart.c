#include "usart.h"

void usart_init(void)
{
    UBRR0H = (UBRRVAL >> 8);
    UBRR0L = UBRRVAL;

    // asynchron, keine Paritaet, 1 Stopbit, 8 Datenbits
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Sender, Empfaenger und Receive-Interrupt an
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}

void usart_send(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}

void usart_send_string(const char *s)
{
    while (*s)
        usart_send((uint8_t)*s++);
}

uint8_t usart_receive(void)
{
    while (!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}
