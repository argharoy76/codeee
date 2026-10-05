#include <stdio.h>

#define EMPTY -1

// Recursive in-order traversal: Left -> Root -> Right
void inOrderTraversal(const int tree[], int index, int totalElements) {
    // Base case: index out of bounds or node is empty
    if (index >= totalElements || tree[index] == EMPTY) {
        return;
    }

    // 1. Visit left child: 2 * index + 1
    inOrderTraversal(tree, 2 * index + 1, totalElements);

    // 2. Visit current node
    printf("%d ", tree[index]);

    // 3. Visit right child: 2 * index + 2
    inOrderTraversal(tree, 2 * index + 2, totalElements);
}

int main() {
    /*
            Tree Structure:
                  1
                /   \
               2     3
              / \     \
             4   5     6

       Array indices:
       Index: 0  1  2  3  4   5  6
       Value: 1  2  3  4  5  -1  6
    */

    int tree[] = {1, 2, 3, 4, 5, EMPTY, 6};
    int totalElements = sizeof(tree) / sizeof(tree[0]);

    printf("In-order Traversal: ");
    inOrderTraversal(tree, 0, totalElements);
    printf("\n");

    return 0;
}