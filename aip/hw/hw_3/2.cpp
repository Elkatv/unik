#include <stdio.h>
#include <stdlib.h>



int main() {

    FILE* f = fopen("f.txt", "r");

    FILE* g = fopen("g.txt", "w");

    char a = getc(f);
    char b = ' ';
    int flag = 0;

    while (a != EOF) {

        if ('A' <= a && a <= 'Z' && b == ' ') {
            flag = 1;
        }

        if (flag == 1) {
            putc(a, g);
        }

        b = a;
        a = getc(f);

        if (a == ' ' && flag == 1) {
            putc(a, g);
            flag = 0;
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}