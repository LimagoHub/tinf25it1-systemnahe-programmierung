#include <iostream>

int main() {
    float kupferreserven = 1'000.0f;
    float jahresverbrauch = 22.0f;
    const float wirtschaftswachstum = 2.0f;
    unsigned char jahre = 0;

    const float faktor = (100.0f + wirtschaftswachstum) / 100.0f;

    while (kupferreserven > 0) {
        kupferreserven -= jahresverbrauch;
        jahresverbrauch *= faktor;
        jahre ++;
    }

    printf("Bei einem Wachstum von %.2f Prozent reichen die Reserven fuer %d Jahre\n", wirtschaftswachstum, jahre);

    return 0;
}
