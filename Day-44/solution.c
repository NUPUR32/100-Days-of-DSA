#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int preorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        arr[index++] = root->val;
        index = preorder(arr, root->left, index);
        index = preorder(arr, root->right, index);
    }
    return index;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));

    *returnSize = preorder(arr, root, 0);

    return arr;
}

int main() {
    // Creating the tree:
    //
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node4 = malloc(sizeof(struct TreeNode));
    struct TreeNode* node5 = malloc(sizeof(struct TreeNode));

    root->val = 1;
    root->left = node2;
    root->right = node3;

    node2->val = 2;
    node2->left = node4;
    node2->right = node5;

    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;

    node4->val = 4;
    node4->left = NULL;
    node4->right = NULL;

    node5->val = 5;
    node5->left = NULL;
    node5->right = NULL;

    int returnSize;

    int* result = preorderTraversal(root, &returnSize);

    printf("Preorder Traversal: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);
    free(node4);
    free(node5);
    free(node3);
    free(node2);
    free(root);

    return 0;
}