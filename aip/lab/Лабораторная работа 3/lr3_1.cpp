#include <iostream>

int main() {
    int a = 12, b = 10, c;

    while (a + b - 2 < 100) {
        c = a + b - 2;
        a = b;
        b = c;   
    }

    std::cout << b;

    return 0;
}
