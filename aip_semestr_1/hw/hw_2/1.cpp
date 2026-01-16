#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int n;
    printf("Введите длину массива: ");
    scanf("%d", &n);

    char h[n];

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        h[i] = rand() % 26 + 65;
    }

    int min;
    char swap;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if ((int)h[j] < (int)h[min]) {
                min = j;
            }
        }
        swap = h[min];
        h[min] = h[i];
        h[i] = swap;
    }

    for (int i = 0; i <n; i++) {
        printf("%c ",h[i]);
    }

    return 0;
}