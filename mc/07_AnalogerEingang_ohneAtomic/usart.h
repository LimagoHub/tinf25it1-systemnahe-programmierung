// USART-API (ATmega328P, USART0) by Jo Wagner

#ifndef JO_USART_H_
#define JO_USART_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// F_CPU kommt aus dem Makefile
#define BAUDRATE 9600UL
#define UBRRVAL  ((F_CPU / (BAUDRATE * 16UL)) - 1)

void usart_init(void);
void usart_send(uint8_t);
void usart_send_string(const char *);
uint8_t usart_receive(void);

#endif
