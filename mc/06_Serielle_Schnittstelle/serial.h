#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>

// F_CPU kommt aus dem Makefile
#define BAUD   9600UL
#define MYUBRR ((F_CPU / (16UL * BAUD)) - 1)    // Klammern wichtig: MYUBRR >> 8

typedef void (*fptr)(uint8_t);

void serial_init(fptr);
void serial_send(uint8_t);
uint8_t serial_receive(void);
/*void serial_send_string(const char *textToSend);
void serial_send_integer(int16_t numberToSend);
void serial_send_double(double numberToSend);
*/
#endif /* SERIAL_H_ */
