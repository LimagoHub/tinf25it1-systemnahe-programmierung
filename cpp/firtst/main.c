#include <stdio.h>

size_t stringlength(char *myArray) {
    size_t result = 0;
    while(myArray[result] ) {
        result++;
    }
    return result;
}




int main(void) {


   // char buffer[]= {'H', 'a', 0};

    char buffer[]= "Hallo";
    printf("%s\n", buffer);
    size_t anzahl = stringlength(buffer);
    return 0;
}
// feld+ index * sizeof(int)
// 3000 + 0 *4