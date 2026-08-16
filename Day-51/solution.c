#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q
) {
    while (root != NULL) {

        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }

    return NULL;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    /*
              6
             / \
            2   8
           / \ / \
          0  4 7  9
            / \
           3   5
    */

    struct TreeNode* root = createNode(6);

    root->left = createNode(2);
    root->right = createNode(8);

    root->left->left = createNode(0);
    root->left->right = createNode(4);

    root->right->left = createNode(7);
    root->right->right = createNode(9);

    root->left->right->left = createNode(3);
    root->left->right->right = createNode(5);

    /* Example 1: p = 2, q = 8 */

    struct TreeNode* p = root->left;
    struct TreeNode* q = root->right;

    struct TreeNode* lca =
        lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA of %d and %d = %d\n",
               p->val, q->val, lca->val);
    }

    /* Example 2: p = 2, q = 4 */

    p = root->left;
    q = root->left->right;

    lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA of %d and %d = %d\n",
               p->val, q->val, lca->val);
    }

    freeTree(root);

    return 0;
}