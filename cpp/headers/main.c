#include <stdio.h>


#include "myio.h"

typedef int(*MyType)();
typedef double(*Operation)(double, double);

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mult(double a, double b) {
    return a * b;
}

double div(double a, double b) {
    return a / b;
}

int sinnDesLebes() {
    return 42;
}

int main(void) {

    Operation ops[] = {add, sub, mult, div};
    ops[0](1.0, 2.0);
    ops[1](1.0, 2.0);
    ops[2](1.0, 2.0);
    ops[3](1.0, 2.0);
    return 0;
}




