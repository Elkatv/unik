#include <iostream>

int main() {
    int a = 12, b = 10;

    for (int c = a + b - 2; c < 100; c = c + a + b - c - 2) {
        a = b;
        b = c;
    }

    std::cout << b;

    return 0;
}