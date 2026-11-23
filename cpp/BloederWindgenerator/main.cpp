#include <iostream>
class CWindgenerator {
private:
    unsigned int uiDrehzahl;
public:
    CWindgenerator() {
        uiDrehzahl = 0;
    }

    unsigned int getDrehzahl() const {
        return uiDrehzahl;
    }

    bool Drehzahl3040() {

        return uiDrehzahl >= 30 && uiDrehzahl <=40;

    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
