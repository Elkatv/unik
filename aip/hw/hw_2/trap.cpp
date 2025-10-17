#include <iostream>

#include "trap.h"

using namespace std;


void trap(double (*func) (double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }

    sum += (func(a) + func(b)) / 2;
    sum *= h;

    printf("%lf", sum);
}