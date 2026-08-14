#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Level Order Traversal
int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {

    // If tree is empty
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Maximum number of nodes according to constraints
    int maxNodes = 2000;

    // Queue for BFS
    struct TreeNode** queue =
        (struct TreeNode**)malloc(maxNodes * sizeof(struct TreeNode*));

    int front = 0;
    int rear = 0;

    // Result
    int** result =
        (int**)malloc(maxNodes * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(maxNodes * sizeof(int));

    *returnSize = 0;

    // Add root to queue
    queue[rear++] = root;

    // BFS
    while (front < rear) {

        // Number of nodes in current level
        int levelSize = rear - front;

        // Allocate memory for current level
        int* currentLevel =
            (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode* current = queue[front++];

            // Store node value
            currentLevel[i] = current->val;

            // Add left child
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }

            // Add right child
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }

        // Store current level
        result[*returnSize] = currentLevel;

        // Store size of current level
        (*returnColumnSizes)[*returnSize] = levelSize;

        (*returnSize)++;
    }

    free(queue);

    return result;
}

// Print result
void printResult(int** result,
                 int returnSize,
                 int* returnColumnSizes) {

    printf("[");

    for (int i = 0; i < returnSize; i++) {

        printf("[");

        for (int j = 0; j < returnColumnSizes[i]; j++) {

            printf("%d", result[i][j]);

            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }

        printf("]");

        if (i < returnSize - 1) {
            printf(",");
        }
    }

    printf("]\n");
}

// Main function for VS Code testing
int main() {

    /*
              3
             / \
            9   20
               /  \
              15   7

        Expected:
        [[3],[9,20],[15,7]]
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int returnSize;
    int* returnColumnSizes;

    int** result =
        levelOrder(root, &returnSize, &returnColumnSizes);

    printResult(result, returnSize, returnColumnSizes);

    // Free result memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    // Free tree
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}