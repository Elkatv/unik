#include <stdio.h>



int main() {
    int n, k;
    char x;

    scanf("%d", &n);

    if (n % 11 == 0) {
        for (int i = 0; i < n; i++) {
            x = getchar();
            k = n % 11;
            if (k == 0 && x != '7' || k == 1 && x != '9') {
                printf("0");
                return 0;
            }
        }
        printf("0");
    } else {
        printf("1");
    }
    
    return 0;
}