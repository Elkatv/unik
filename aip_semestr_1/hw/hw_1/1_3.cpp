#include <stdio.h>
#include <math.h>

double sincos(double x) {
    return pow(cos(x), 2) + pow(sin(x), 2);
}

int main() {

    for (double i = 0; i < 20; i++) {
        printf("x = %d : %lf\n", (int)i ,sincos(i));
    }

    return 0;
}