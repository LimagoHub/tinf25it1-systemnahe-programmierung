#include <iostream>

class Radio {
public:
    Radio() {
        lautstaerke_ = 0.0;
    }

    Radio(double lautstaerke){
        if (lautstaerke >= 0.0) {
            lautstaerke_ = lautstaerke;
        } else {
            lautstaerke_ = 0.0;
        }
    }

    void lauter() {
        lautstaerke_ ++;
    }
    void lauter(double wert) {
        lautstaerke_ += wert;
        if (lautstaerke_ < 0.0) {
            lautstaerke_ = 0.0;
        }
    }
    void leiser() {
        lautstaerke_ --;
        if (lautstaerke_ < 0.0) {
            lautstaerke_ = 0.0;
        }
    }

    double get_lautstaerke()  {
        return lautstaerke_;
    }

    bool istEingeschaltet()  {
        if (lautstaerke_ > 0.0) {
            return true;
        } else {
            return false;
        }
    }
private:
    double lautstaerke_;
};



int main() {

  Radio radio(10);

    while (radio.istEingeschaltet()) {
        printf("%.2lf\n", radio.get_lautstaerke());
        radio.leiser();
    }


    return 0;
}
