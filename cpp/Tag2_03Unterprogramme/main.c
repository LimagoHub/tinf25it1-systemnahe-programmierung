#include <cstdlib>
#include <stdio.h>

// Vorwaertsdeclaration
// prototypendeclaration

double addition(double a, double b); // Parameter Aufrufargument
double Quadrat(double x);
unsigned long multipliziere(unsigned int a, unsigned int b);

int main() {


    unsigned long ergebnis = multipliziere(5, 3);


    unsigned int a = 0;

    a = ~ a;


    double result = Quadrat(5.0);


    printf("a = %ud\n", a);

    if ( a) {
        printf("wahr\n");
    } else {
        printf("falsch\n");
    }

   /* for (double i = -3.0; i <= 3.0; i += 0.5)
    {
        double result = Quadrat(i);
        printf("Quadrat von %.2lf ist %.2lf\n", i, result);
    }

    */
    return 0;
}

double Quadrat(double x)
{
    return x*x;
}


double addition(double a, double b)
{

    return a + b;
}

unsigned long multipliziere(unsigned int a, unsigned int b){
    unsigned long result = 0;

    if (a < b) {
        unsigned int temp = a;
        a = b;
        b = temp;
    }

    for (int i = 0; i < b; ++i) {
        result += a;
    }

    return result;
}


