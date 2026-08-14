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

// Function to insert a value into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {

    // If we reach an empty position, create a new node
    if (root == NULL) {
        struct TreeNode* newNode =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));

        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    // Smaller values go to the left
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }

    // Larger values go to the right
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal to print the BST
void inorder(struct TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->val);

    inorder(root->right);
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

        Insert: 5

        After insertion:

              4
             / \
            2   7
           / \  /
          1   3 5
    */

    // Create the initial tree
    struct TreeNode* root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(7);

    root->left->left = createNode(1);
    root->left->right = createNode(3);

    printf("BST before insertion:\n");
    inorder(root);

    // Value to insert
    int val = 5;

    // Insert value into BST
    root = insertIntoBST(root, val);

    printf("\n\nBST after inserting %d:\n", val);
    inorder(root);

    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}