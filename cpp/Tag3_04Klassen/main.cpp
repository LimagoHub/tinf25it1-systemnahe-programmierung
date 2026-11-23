#include <iostream>
#include <ostream>
#include <string>

class Schwein { // Klasse
public:
    Schwein() {
        std::cout << "Schwein created" << std::endl;
        name = "Nobody";
        gewicht = 10;
    }

    void fuettern() {
        gewicht += 1;
    }

    std::string get_name() const {
        return name;
    }

    void set_name(const std::string &name) {
        this->name = name;
    }

    int get_gewicht() const {
        return gewicht;
    }

    friend std::ostream & operator<<(std::ostream &os, const Schwein &obj) {
        return os
               << "name: " << obj.name
               << " gewicht: " << obj.gewicht;
    }

private:
    std::string name; // Eigenschaft oder Attribute
    int gewicht;
    void set_gewicht(int gewicht) {
        this->gewicht = gewicht;
    }


};

int main() {
    Schwein piggy; // Instanz bzw. Object

    piggy.set_name("Miss Piggy");
    //std::cout << piggy.get_name() << " ist " << piggy.get_gewicht() << " kg schwer." << std::endl;

    std::cout << piggy << std::endl;
    piggy.fuettern();
    //std::cout << piggy.get_name() << " ist " << piggy.get_gewicht() << " kg schwer." << std::endl;
    std::cout << piggy << std::endl;
    return 0;
}
