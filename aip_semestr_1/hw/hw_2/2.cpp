#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char str[42];
    char new_str[42];

    srand((unsigned)time(NULL));
    for (int i = 0; i < 41; i++) {
        if (i % 7 == 6) {
            str[i] = ' ';
        } else {
            str[i] = (char)((rand() % 26) + 65);
        }
    }
    str[41] = '\0';

    printf("%s\n", str);

    int flag = 1;
    char word[6];

    for (int i = 0; i < 42; i+=7) {
        flag = 1;
        for (int j = i; j-i < 6;j++) {
            if ('A' == str[j] || 'D' == str[j] || 'E' == str[j]) {
                flag = 0;
            }
            word[j-i] = str[j];
        }
        if (flag == 0) {
            strcat(new_str, word);
            strcat(new_str, " ");
        }
    }

    printf("%s", new_str);

    return 0;
}