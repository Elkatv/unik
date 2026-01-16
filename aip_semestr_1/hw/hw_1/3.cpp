#include <stdio.h>
#include <math.h>


int main() {
    double esp;
    printf("Введите точность вычисления: ");
    scanf("%lf", &esp);
    
    double s = 0;
    int n = 0;

    for (double i = 0; i < 1; i += esp) {
        s += (esp * n) * sqrt(1 - (esp * n) * (esp * n));
        n += 1;
    }

    s /= n;

    printf("Площадь: %.6f\nКлоличество отрезков рвзбиения: %d", s, n);

    return 0;
}