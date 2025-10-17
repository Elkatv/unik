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

    char a;
    scanf("%c", &a);

    head->elem = a;
    head->next = nullptr;

    bool flag = true;
    int c = 2;
    while (flag) {
        a = getchar();
        if (a == '.') {
            flag = false;
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

    free_list(head);

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