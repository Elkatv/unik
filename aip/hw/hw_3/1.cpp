#include <stdio.h>
#include <stdlib.h>

struct stack {
    char str[32];
    stack* next;
};

int main() {
    int n = 1024;
    char string[n];

    fgets(string, sizeof(string), stdin);

    stack* root = (stack*)malloc(sizeof(stack));

    for (int i = 0; i < n; i++) {
        
    }


    return 0;
}