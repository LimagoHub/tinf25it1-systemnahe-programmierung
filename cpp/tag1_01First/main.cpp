#include <iostream>
using namespace std;
int main() {

    unsigned int uiA=3;
    unsigned int uiB=4 ;
    unsigned long ulErgebnis=0;

    for (unsigned int i=0; i<uiA; i++) {
        ulErgebnis +=  uiB;
    }
    cout << ulErgebnis << endl;
    return 0;
}
