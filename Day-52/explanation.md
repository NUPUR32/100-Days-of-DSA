# Lowest Common Ancestor of a Binary Tree

## Problem

Given a binary tree and two nodes `p` and `q`, find their **Lowest Common Ancestor (LCA)**.

The Lowest Common Ancestor is the lowest node in the tree that has both `p` and `q` as descendants.

A node is also considered a descendant of itself.

---

## Example

Consider the following binary tree:

```text
          3
        /   \
       5     1
      / \   / \
     6   2 0   8
        / \
       7   4
```

### Example 1

```text
p = 5
q = 1
```

Output:

```text
3
```

Node `5` is in the left subtree of `3` and node `1` is in the right subtree of `3`.

Therefore, their Lowest Common Ancestor is `3`.

### Example 2

```text
p = 5
q = 4
```

Output:

```text
5
```

Node `4` is a descendant of node `5`.

Since a node can be considered a descendant of itself, the LCA is `5`.

---

## Approach

We use **recursion / Depth First Search (DFS)**.

Starting from the root, we search for `p` and `q` in both the left and right subtrees.

### Base Case

```c
if (root == NULL) {
    return NULL;
}
```

If the current node does not exist, return `NULL`.

We also check whether the current node is `p` or `q`:

```c
if (root == p || root == q) {
    return root;
}
```

If it is, return the current node.

---

## Recursive Search

Search the left subtree:

```c
struct TreeNode* left =
    lowestCommonAncestor(root->left, p, q);
```

Search the right subtree:

```c
struct TreeNode* right =
    lowestCommonAncestor(root->right, p, q);
```

Now there are three important cases.

### Case 1: Both Left and Right Are Not NULL

```c
if (left != NULL && right != NULL) {
    return root;
}
```

This means one target node was found on the left side and the other was found on the right side.

Therefore, the current `root` is their Lowest Common Ancestor.

### Case 2: Only Left Is Not NULL

```c
if (left != NULL) {
    return left;
}
```

Both target nodes are associated with the left subtree, so return the result obtained from the left side.

### Case 3: Only Right Is Not NULL

```c
return right;
```

The required node or LCA was found in the right subtree.

---

## Algorithm

1. Start from the root.
2. If `root` is `NULL`, return `NULL`.
3. If `root` is equal to `p` or `q`, return `root`.
4. Recursively search the left subtree.
5. Recursively search the right subtree.
6. If both searches return non-`NULL`, the current root is the LCA.
7. Otherwise, return whichever subtree returned a non-`NULL` result.

---

## Dry Run

For:

```text
p = 5
q = 4
```

Tree:

```text
          3
        /   \
       5     1
      / \
     6   2
        / \
       7   4
```

When recursion reaches node `5`, we have:

```c
root == p
```

Therefore:

```c
return root;
```

Node `5` is returned upward through the recursive calls.

Hence:

```text
LCA = 5
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

In the worst case, we visit every node of the binary tree once.

Here, `n` is the number of nodes in the tree.

### Space Complexity

```text
O(h)
```

The recursive call stack depends on the height `h` of the tree.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

---

## Key Concept

The most important condition is:

```c
if (left != NULL && right != NULL) {
    return root;
}
```

If `p` and `q` are found in different subtrees of a node, that node is their **Lowest Common Ancestor**.
