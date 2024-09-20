#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} node;

int main(int argc, char* argv[])
{
    node* list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        node* n = malloc(sizeof(node));
        if (n == NULL) {
            free(list);
            free(n);

            return 1;
        }

        n->number = number;
        n->next = list;

        list = n;
    }

    node* ptr = list;
    while (ptr) {
        printf("Address: %p\nValue: %i\n", &ptr->number, ptr->number);
        ptr = ptr->next;
    }

    free(ptr);
    free(list);
    return 0;
}
