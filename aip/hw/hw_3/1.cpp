#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct simple_list {
    char* word;
    simple_list* next;
};

simple_list* add(simple_list* head, char* value);
void output(simple_list* head);
void free_list(simple_list* head);

int main() {
    simple_list* head = NULL;

    // simple_list* root = head;
    
    char input[1024];

    fgets(input, sizeof(input), stdin);
    char* word = strtok(input, " ");

    while (word != NULL) {

        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }

        head = add(head, word);

        word = strtok(NULL, " ");
    }
    output(head);
    free_list(head);

}

simple_list* add(simple_list* head, char* value) {

    simple_list* len_elem = (simple_list*)malloc(sizeof(simple_list));

    len_elem->word = (char*)malloc(5 * sizeof(char));
    snprintf(len_elem->word, 5, "%d", (int)strlen(value));
    len_elem->next = head;

    head = len_elem;


    simple_list* new_elem = (simple_list*)malloc(sizeof(simple_list));

    new_elem->word = (char*)malloc((strlen(value) + 1) * sizeof(char));
    strcpy(new_elem->word, value);
    new_elem->next = head;

    head = new_elem;

    return head;
}

void output(simple_list* head) {
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
}

void free_list(simple_list* head) {
    simple_list* next;
    while (head != nullptr) {
        next = head->next;
        free(head);
        head = next;
    }
}