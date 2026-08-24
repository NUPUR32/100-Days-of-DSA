#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int postStart, int postEnd) {

    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = postorder[postEnd];
    root->left = NULL;
    root->right = NULL;

    int index = inStart;
    while (inorder[index] != root->val)
        index++;

    int leftSize = index - inStart;

    root->left = build(inorder, inStart, index - 1,
                       postorder, postStart, postStart + leftSize - 1);

    root->right = build(inorder, index + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    return build(inorder, 0, inorderSize - 1,
                 postorder, 0, postorderSize - 1);
}

// Preorder Traversal
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {

    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};

    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Preorder Traversal of Constructed Tree:\n");
    preorder(root);

    return 0;
}