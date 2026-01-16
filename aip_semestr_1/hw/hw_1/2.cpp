#include <stdio.h>

int main() {
    double x, y, w, m;
    printf("Введите три числа x y w: ");
    scanf("%lf %lf %lf", &x, &y, &w);

    if (y > w)
        m = x + y;
    else
        m = x + w;

    if (y * w > m)
        m = y * w;

    m = m * m;

    printf("%.4lf", m);

    return 0;
}