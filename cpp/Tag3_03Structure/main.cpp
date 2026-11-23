#include <iostream>

struct Messwert {
    unsigned int temp;
    unsigned int druck;
    unsigned int feuchte;
};

void printMesswert(Messwert m) {
    std::cout << "Messwert: (" << m.temp << ", " << m.druck << ", " << m.feuchte << ")" << std::endl;
}

int main() {

    Messwert m1 = {10, 20, 30};

    Messwert messwerte[]= {
        {10,20,30},
        {40,40,60},
        {40,40,60}
    };

    /*
    messwerte[0]={10,20,30};

    messwerte[1].temp = 40;
    messwerte[1].druck = 50;
    messwerte[1].feuchte = 60;
    */

    return 0;
}
