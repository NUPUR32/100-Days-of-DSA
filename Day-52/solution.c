#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find Lowest Common Ancestor
struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q
) {
    // Base case
    if (root == NULL) {
        return NULL;
    }

    // If current node is p or q
    if (root == p || root == q) {
        return root;
    }

    // Search in left subtree
    struct TreeNode* left =
        lowestCommonAncestor(root->left, p, q);

    // Search in right subtree
    struct TreeNode* right =
        lowestCommonAncestor(root->right, p, q);

    // If p and q are found on different sides
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise return the non-NULL result
    if (left != NULL) {
        return left;
    }

    return right;
}

int main() {

    /*
              3
            /   \
           5     1
          / \   / \
         6   2 0   8
            / \
           7   4
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(5);
    root->right = createNode(1);

    root->left->left = createNode(6);
    root->left->right = createNode(2);

    root->right->left = createNode(0);
    root->right->right = createNode(8);

    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    // Example 1: p = 5, q = 1
    struct TreeNode* p = root->left;
    struct TreeNode* q = root->right;

    struct TreeNode* result =
        lowestCommonAncestor(root, p, q);

    printf("Example 1\n");
    printf("p = %d\n", p->val);
    printf("q = %d\n", q->val);
    printf("Lowest Common Ancestor = %d\n\n", result->val);


    // Example 2: p = 5, q = 4
    p = root->left;
    q = root->left->right->right;

    result = lowestCommonAncestor(root, p, q);

    printf("Example 2\n");
    printf("p = %d\n", p->val);
    printf("q = %d\n", q->val);
    printf("Lowest Common Ancestor = %d\n", result->val);

    return 0;
}