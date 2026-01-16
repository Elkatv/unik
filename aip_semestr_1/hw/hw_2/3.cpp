#include <stdio.h>
#include <math.h>

#include "trap.h"

double func1(double x);
double func2(double x);

int main() {

    int a, b;
    int n;
    printf("Введите количество отрезков разбиения: ");
    scanf("%d", &n);

    printf("Функция sin(x)/x^2: ");
    a = 1;
    b = 2;
    trap(func1, a, b, n);

    printf("\nФункция ln(x)+2x: ");
    a = 1;
    b = 3;
    trap(func2, a, b, n);
}

double func1(double x) {
    return sin(x)/(x * x);
}

double func2(double x) {
    return log(x) + 2 * x;
}