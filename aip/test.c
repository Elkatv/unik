#include <stdio.h>

int main() {
    int a = 0, b = 1;

    int * aa = &a;
    
    printf("%d", *aa);
    aa += 8;
    printf("%d", *aa);



    return 0;
}