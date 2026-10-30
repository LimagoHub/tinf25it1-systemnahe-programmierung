#include <stdio.h>
#include <stdlib.h>



size_t stringlength(char *myArray) BEGIN


    size_t result = 0;
    while(myArray[result] ) {
        result++;
    }
    return result;
}
void stringcopy(char *destination, const char * source) {
    while (*destination++ = *source++);

}


char * gibMirAs(size_t size ) {
    char *buffer= (char*)malloc((size + 1) *sizeof(char));
    size_t i;
    for(i = 0; i < size; i++) {
        buffer[i] = 'A';
    }
    buffer[i] = 0;
    return buffer;
}


int main(void) {


   char *a = gibMirAs(10);
    printf("%s\n", a);

    free(a);
    return 0;
}
// feld+ index * sizeof(int)
// 3000 + 0 *a