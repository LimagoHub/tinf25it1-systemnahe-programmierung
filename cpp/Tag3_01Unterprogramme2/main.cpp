#include <iostream>




void unter(int &a) {
    a = 100;
}

void ober() {
    int x = 10;
    unter(x);
    std::cout << x << std::endl;
}

void tausche(int &a, int &b);



int main() {

   int x =10;
    int y = 20;
    tausche(x,y);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    return 0;
}
void tausche(int &a, int &b) {
    int help = a;
    a = b;
    b = help;
}