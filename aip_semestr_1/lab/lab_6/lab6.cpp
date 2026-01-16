#include <stdio.h>
#include <stdlib.h>


struct simple_list {
    char elem;
    simple_list* next;
};

void add(simple_list* head, char enw_elem);
void free_list(simple_list* head);

int main() {
    simple_list* head = (simple_list*)malloc(sizeof(struct simple_list));
    simple_list* root = head;

    char a;
    scanf("%c", &a);

    head->elem = a;
    head->next = nullptr;

    int flag = 1;
    int c = 2;
    while (flag == 1) {
        a = getchar();
        if (a == '.') {
            flag = 0;
        } else {
            add(head, a);
            c += 1;
        }
    }

    int count = 1;
    while (count < c) {
        if (count % 2 == (c + 1) % 2)
            printf("%c ", head->elem);
        head = head->next;
        count += 1;
    }

    free_list(root);

}

void add(simple_list* head, char value) {
    while (head->next != nullptr) {
        head = head->next;
    }

    simple_list* new_elem = (simple_list*)malloc(sizeof(struct simple_list));
    new_elem->elem = value;
    new_elem->next = nullptr;
    head->next = new_elem;
}

void free_list(simple_list* head) {
    simple_list* next;
    while (head != nullptr) {
        next = head->next;
        free(head);
        head = next;
    }
}