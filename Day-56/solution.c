#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Check if two trees are mirror images
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
        return false;

    if (left->val != right->val)
        return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check if tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    /*
            1
          /   \
         2     2
        / \   / \
       3  4  4  3
    */

    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(4);

    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if (isSymmetric(root))
        printf("Tree is Symmetric\n");
    else
        printf("Tree is Not Symmetric\n");

    return 0;
}