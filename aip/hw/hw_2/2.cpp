#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int n = 42;

    char str[n];

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        if (0 < i % 7 && i % 7 < 6){
            str[i] = rand() % 26 + 65;
        } else if (i % 7 == 6 && i != n - 1){
            str[i] = ' ';
        } else {
            str[i] = '\0';
        }
    }

    for (int i = 0; i < n; i += 7) {
        
    }

    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }

    return 0;
}

