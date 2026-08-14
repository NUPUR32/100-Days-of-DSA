#include <stdio.h>
#include <stdlib.h>

// Definition of binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {

    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to calculate sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {

    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    // Check whether left child is a leaf
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {

        sum += root->left->val;
    }
    else {
        sum += sumOfLeftLeaves(root->left);
    }

    // Check the right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
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

    int result = sumOfLeftLeaves(root);

    printf("Sum of Left Leaves: %d\n", result);

    // Free allocated memory
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}