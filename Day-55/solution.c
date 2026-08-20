#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 101

// Definition for a binary tree node
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

// Right Side View Function
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (root == NULL)
        return NULL;

    struct TreeNode* queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int* result = (int*)malloc(MAX_NODES * sizeof(int));

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            // Last node of the current level
            if (i == levelSize - 1)
                result[*returnSize] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4

    Expected Output:
    1 3 4
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(4);

    int returnSize;
    int* result = rightSideView(root, &returnSize);

    printf("Right Side View: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);
    freeTree(root);

    return 0;
}