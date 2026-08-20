#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 2000

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **result = (int **)malloc(MAX_NODES * sizeof(int *));
    *returnColumnSizes = (int *)malloc(MAX_NODES * sizeof(int));

    struct TreeNode *queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = root;

    bool leftToRight = true;

    while (front < rear) {
        int levelSize = rear - front;

        result[*returnSize] = (int *)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = queue[front++];

            int index;
            if (leftToRight)
                index = i;
            else
                index = levelSize - 1 - i;

            result[*returnSize][index] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        leftToRight = !leftToRight;
        (*returnSize)++;
    }

    return result;
}

// Free the tree
void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
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

    int returnSize;
    int *returnColumnSizes;

    int **result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

    printf("Zigzag Level Order Traversal:\n");

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    freeTree(root);

    return 0;
}