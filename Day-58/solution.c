#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create Node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int preIndex = 0;

// Build Tree
struct TreeNode* build(int preorder[], int inorder[], int left, int right) {
    if (left > right)
        return NULL;

    struct TreeNode* root = createNode(preorder[preIndex++]);

    int mid = left;
    while (inorder[mid] != root->val)
        mid++;

    root->left = build(preorder, inorder, left, mid - 1);
    root->right = build(preorder, inorder, mid + 1, right);

    return root;
}

struct TreeNode* buildTree(int preorder[], int preorderSize,
                           int inorder[], int inorderSize) {
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}

// Print Inorder
void printInorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Print Preorder
void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Preorder Traversal: ");
    printPreorder(root);

    printf("\nInorder Traversal: ");
    printInorder(root);

    return 0;
}