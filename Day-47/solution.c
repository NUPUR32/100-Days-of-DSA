#include <stdio.h>
#include <stdlib.h>

// Definition of binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find maximum depth
int maxDepth(struct TreeNode* root) {

    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int main() {

    /*
            3
           / \
          9   20
             /  \
            15   7
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int depth = maxDepth(root);

    printf("Maximum Depth: %d\n", depth);

    // Free allocated memory
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}