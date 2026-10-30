#include <stdio.h>


#include "MyIo.h"

int main(int argc, char **argv, char **env) {

    printf("%d \n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s \n", argv[i]);
    }

    while (*env) {
        printf("%s \n", *env++);

    }
    return 0;
}


