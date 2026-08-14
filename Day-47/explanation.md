We can solve this problem using Depth-First Search (DFS).

For every node:

1.Find the maximum depth of its left subtree.
2.Find the maximum depth of its right subtree.
3.Take the larger depth.
4.Add 1 for the current node.

The main formula is:

depth = 1 + max(leftDepth, rightDepth)
Base Case

If the current node is NULL, its depth is 0.

if (root == NULL) {
    return 0;
}