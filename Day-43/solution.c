#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Inorder traversal function
int inorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        index = inorder(arr, root->left, index);

        arr[index++] = root->val;

        index = inorder(arr, root->right, index);
    }

    return index;
}

// Main inorder traversal function
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));

    *returnSize = inorder(arr, root, 0);

    return arr;
}

// Create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {

    /*
             1
              \
               2
              /
             3

        Inorder = 1 3 2
    */

    struct TreeNode* root = createNode(1);

    root->right = createNode(2);
    root->right->left = createNode(3);

    // Perform inorder traversal
    int returnSize;

    int* result = inorderTraversal(root, &returnSize);

    // Print result
    printf("Inorder Traversal: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    // Free allocated memory
    free(result);

    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}