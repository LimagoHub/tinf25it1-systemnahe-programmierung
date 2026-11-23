#include <iostream>
#include <ostream>

class Punkt {
private:
    const double MAX = 10;
    double x_;
    double y_;

    void set_x(double x) {
        if (x >= MAX) x = MAX;
        if (x < -MAX) x = -MAX;
        x_ = x;
    }

    void set_y(double y) {
        y_ = y;
    }
public:
    Punkt() {
        x_ = 0;
        y_ = 0;
    }
    ~Punkt() {
        std::cout << "Punkt destroyed" << std::endl;
    }

    Punkt(double x, double y) {
        set_x(x);
        set_y(y);
    }

    double get_x() const {
        return x_;
    }



    double get_y() const {
        return y_;
    }

    friend std::ostream & operator<<(std::ostream &os, const Punkt &obj) {
        return os
               << "x_: " << obj.x_
               << " y_: " << obj.y_;
    }

    void rechts() {
        set_x(get_x() + 1);
    }

    void rechts(double schrittweite) {
        set_x(get_x() + schrittweite);
    }

    void linkss() {
        set_x(get_x() - 1);
    }
};


int main() {
    Punkt p(1,3);
    std::cout << p << std::endl;

    for (int i = 0; i < 11; ++i) {
        p.rechts(0.5);
        std::cout << p << std::endl;
    }


    return 0;
}
