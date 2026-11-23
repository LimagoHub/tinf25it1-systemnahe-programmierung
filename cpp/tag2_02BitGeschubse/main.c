#include <stdio.h>


#define ABC 0
#define XYZ 1
#define ATLAR 5
#define REFS0 6

int main(void) {


   unsigned char value = 0b10101010;


    printf("%b\n", value);


   // unsigned char ADMUX =     0b10100001;
    //                        0b00100000
   //                         -----------

    //                        0b00100000;
    //int a = 10;

    //while ((ADMUX & (1 << ATLAR)) != 0);

    /*unsigned char ADMUX =     0b10000001;

    ADMUX |= (1 << ATLAR) | (1 << REFS0);


    printf("%b\n", ADMUX);

    ADMUX &= ~(1 << ATLAR);

    printf("%b\n", ADMUX);

    ADMUX ^= (1 << ATLAR);

    printf("%b\n", ADMUX);
    */
    return 0;
}
