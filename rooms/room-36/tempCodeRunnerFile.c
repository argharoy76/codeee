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