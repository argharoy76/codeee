#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node* root = NULL;
    char buffer[4096];

    printf("Enter numbers:\n");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char* ptr = buffer;
        int value, bytesRead;

        while (sscanf(ptr, "%d%n", &value, &bytesRead) == 1) {
            root = insert(root, value);
            ptr += bytesRead;
        }
    }

    printf("\nPreorder Traversal:\n");
    preorder(root);
    printf("\n");

    return 0;
}