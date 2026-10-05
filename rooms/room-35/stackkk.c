#include <stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void push(struct Node** top, char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    struct Node* temp = *top;
    char value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int main() {
    struct Node* stack = NULL;
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            push(&stack, str[i]);
        }

        printf("Reversed: ");
        while (stack != NULL) {
            putchar(pop(&stack));
        }
        printf("\n");
    }

    return 0;
}