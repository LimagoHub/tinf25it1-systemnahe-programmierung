#include <iostream>

#define MAX(a,b) (a>b?a:b)

int max(int a, int b) {
    return (a>b?a:b);
}

int main() {
    int x = 20;
    int y = 30;
    int z = max(++x,++y);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
