#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Flatten Binary Tree
void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* leftTree = root->left;
    struct TreeNode* rightTree = root->right;

    root->left = NULL;
    root->right = leftTree;

    struct TreeNode* curr = root;
    while (curr->right != NULL)
        curr = curr->right;

    curr->right = rightTree;
}

// Print flattened linked list
void printList(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

int main() {
    /*
            1
          /   \
         2     5
        / \     \
       3   4     6
    */

    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(5);

    root->left->left = createNode(3);
    root->left->right = createNode(4);

    root->right->right = createNode(6);

    flatten(root);

    printf("Flattened Tree:\n");
    printList(root);

    return 0;
}