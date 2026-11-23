#include <iostream>

void macheEtwasMitArray(int array[], int groesse) {
    array[0] = 100;
}



int main() {
   int feld[] = {2,90,15,4,30};

   int  max=feld[0];

    for(int i=1; i<5; i++) {
        if (max < feld[i]) {
            max = feld[i];
        }
    }

   std::cout << "Maxvalue = " << max << std::endl;

    return 0;
}
