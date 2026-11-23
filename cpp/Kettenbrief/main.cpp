#include <iostream>

int main() {
    const unsigned long long weltbevoelkerung = 8'000'000'000ULL;
    const unsigned int nachfolger = 2;
    unsigned int generationen = 1;
    unsigned long long anzahlSpieler = 1ULL;

    while (anzahlSpieler < weltbevoelkerung) {
        generationen++;
        anzahlSpieler *= nachfolger;
    }


    printf("Nach %u Generationen haben alle Menschen der Erde mitgespielt!\n",generationen);
    return 0;
}
