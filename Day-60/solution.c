#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int cameras = 0;

// 0 -> Needs Camera
// 1 -> Has Camera
// 2 -> Covered
int dfs(struct TreeNode* root)
{
    if (root == NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0)
    {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 2;

    return 0;
}

int minCameraCover(struct TreeNode* root)
{
    cameras = 0;

    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

int main()
{
    /*
            0
           /
          0
         / \
        0   0

    Answer = 1
    */

    struct TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->right = createNode(0);

    printf("Minimum Cameras Required = %d\n", minCameraCover(root));

    return 0;
}