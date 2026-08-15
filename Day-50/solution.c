#include <stdio.h>
#include <stdlib.h>

// Definition of a Binary Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Search for a node with the given value in the BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {

    // Base case: node not found or value found
    if (root == NULL || root->val == val) {
        return root;
    }

    // If val is smaller, search in the left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    // If val is larger, search in the right subtree
    return searchBST(root->right, val);
}

// Preorder traversal to print the subtree
void printSubtree(struct TreeNode* node) {

    if (node == NULL) {
        return;
    }

    printf("%d ", node->val);

    printSubtree(node->left);
    printSubtree(node->right);
}

// Free dynamically allocated tree
void freeTree(struct TreeNode* root) {

    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main() {

    /*
        Initial BST:

              4
             / \
            2   7
           / \
          1   3

        Search: 2

        Result subtree:

            2
           / \
          1   3
    */

    // Create the tree
    struct TreeNode* root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(7);

    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Value to search
    int val = 2;

    // Search for the node
    struct TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        printf("Subtree rooted at node with value %d:\n", val);
        printSubtree(result);
        printf("\n");
    } else {
        printf("Node with value %d not found in the BST.\n", val);
    }

    // Free allocated memory
    freeTree(root);

    return 0;
}