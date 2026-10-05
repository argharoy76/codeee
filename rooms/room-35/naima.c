#include <stdio.h>
#include <stdlib.h>

// Definition of a BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to allocate a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Duplicate values are ignored

    return root;
}

// In-order traversal: Left -> Root -> Right (Produces ascending order)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free allocated memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        freeTree(root);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("How many values do you want to insert? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d numbers (space or newline separated):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nBST elements in ascending order:\n");
    inOrderTraversal(root);
    printf("\n");

    // Free memory
    freeTree(root);

    return 0;
}