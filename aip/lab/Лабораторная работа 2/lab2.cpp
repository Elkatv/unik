#include <iostream>


int main () {
    double x, y;
    
    std::cout << "Введите два числа через пробел х у: ";
    std::cin >> x >> y;

        if (y < x && x * x + y * y < 1.0) {
            std::cout << "Точка попадает в выделенную область";
        } else {
            std::cout << "Точка не попадает в выделенную область";
        }
    return 0;
}
