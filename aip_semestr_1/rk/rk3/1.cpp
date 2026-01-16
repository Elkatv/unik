#include <stdio.h>
#include <stdlib.h>

struct simple_list {
    int value;
    struct simple_list *prev, *next;
};

void output(simple_list* head);
void free_list(simple_list* head);

int main() {
    simple_list *head = NULL, *tail = NULL;

    int x;
    scanf("%d", &x);
    while (x != 0) {
        simple_list *node = (simple_list *)malloc(sizeof(simple_list));
        node->value = x;
        node->prev = NULL;
        node->next = head;

        if (head)
            head->prev = node;
        else
            tail = node;
        head = node;
        scanf("%d", &x);
    }


    int tmp = head->value;
    head->value = tail->value;
    tail->value = tmp;


    output(head);
    free_list(head);
    return 0;
}

void output(simple_list* head) {
    simple_list *cur = head;
    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
}

void free_list(simple_list* head){
    simple_list* cur = head;
    while (cur) {
        simple_list *next = cur->next;
        free(cur);
        cur = next;
    }
}