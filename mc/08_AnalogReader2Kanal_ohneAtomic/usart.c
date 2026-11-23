#include "usart.h"

void usart_init(void)
{
    UBRR0H = (UBRRVAL >> 8);
    UBRR0L = UBRRVAL;

    // asynchron, keine Paritaet, 1 Stopbit, 8 Datenbits
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Sender und Empfaenger an
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
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

void usart_send_uint16(uint16_t value)
{
    char buffer[6];
    utoa(value, buffer, 10);
    usart_send_string(buffer);
}
