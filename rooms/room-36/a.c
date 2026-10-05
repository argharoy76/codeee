#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to allocate and initialize a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder traversal: Root -> Left -> Right
void printPreorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // 1. Visit root
    printf("%d ", root->data);

    // 2. Traverse left subtree
    printPreorder(root->left);

    // 3. Traverse right subtree
    printPreorder(root->right);
}

// Free allocated memory to avoid leaks
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /* 
       Constructing the following binary tree:
               1
             /   \
            2     3
           / \     \
          4   5     6
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}