#include <string.h>
#include <stdlib.h>
#include <iostream>

#define LEN_WORD 32
#define LEN_STRING 100 

struct stack {
    char str[LEN_WORD];
    stack* next;
};

void add(stack* root, char* strin, int a, int b) {
    stack* elem = (stack*)malloc(sizeof(stack));

    for(int i = a; i < a + (b - a) % 31; i++) {
        elem->str[i - a] = strin[i];
    }
    elem->next = nullptr;

    while(root->next != NULL) {
        root = root->next;
    }
    root->next = elem;
}

void output(stack* root) {
    while(root->next != NULL) {
        std::cout << root->str;
        root = root->next;
    }
}

void free_stack(stack* root) {
    stack* elem = root;
    while(root->next != NULL) {
        elem = root->next;
        free(root);
        root = elem;
    }
    free(elem);
    free(root);
}

void output_str(char* str, int a, int b) {
    for (int i = a; i < b; i++) {
        std::cout << str[i];
    }
    std::cout <<std::endl;

}

int main() {
    char str[LEN_STRING];

    std::cin.getline(str, LEN_STRING - 1, '\n');

    stack* root = (stack*)malloc(sizeof(stack));
    root->str[0] = '\0';
    root->next = nullptr;

    int j = 0; 
    int flag;
    char* word[LEN_WORD];

    std::cout << str << std::endl;
    for (int i = 0; i < LEN_STRING; i += j) {
        j = i;
        flag = 1;

        while (flag == 1) {
            if (str[j] == ' ') {
                flag = 0;
            }
            j++;
        }

        output_str(str, i, j);

        

        

        add(root, str, i, j);
        
    }

    output(root);
    free_stack(root);


    return 0;
}