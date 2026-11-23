#include <iostream>

int main() {
    int tag =2;


    switch (tag) {
        case 1:
            std::cout << "Montag" << std::endl;
            break;
        case 2:
            std::cout << "Dienstag" << std::endl;
            break;
        case 3:
            std::cout << "Mittwoch" << std::endl;
            break;
        case 4:
            std::cout << "Donnerstag" << std::endl;
            break;
        case 5:
            std::cout << "Freitag" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Wochenende" << std::endl;
            break;
        default:
            std::cout << "Diesen Tag gibt es nicht" << std::endl;
            break;
    }
    return 0;
}
