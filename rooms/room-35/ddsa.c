#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Inserted %d at the beginning.\n", new_data);
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void searchValue(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    int found = 0;

    while (current != NULL) {
        if (current->data == key) {
            printf("Value %d found at position %d.\n", key, position);
            found = 1;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        printf("Value %d not found\n", key);
    }
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, n;

    printf("Num of nodes: ");
    if (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 1; i <= n; i++) {
            printf("node %d: ", i);
            scanf("%d", &value);
            insertAtEnd(&head, value);
        }
        printf("Initial list created successfully!\n");
    } else {
        printf("Starting with an empty list.\n");
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Traverse\n");
        printf("2. Node Count\n");
        printf("3. Search\n");
        printf("4. Insert Beginning\n");
        printf("5. Exit\n");
        printf("Enter (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                traverseList(head);
                break;

            case 2:
                printf("Total nodes: %d\n", countNodes(head));
                break;

            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchValue(head, value);
                break;

            case 4:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 5:
                freeList(head);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }

    freeList(head);
    return 0;
}