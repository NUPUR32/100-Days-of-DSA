# 56. Symmetric Tree

## Approach

A binary tree is symmetric if its left and right subtrees are mirror images of each other.

We create a helper function `isMirror(left, right)`.

### Cases

1. If both nodes are `NULL`, they are symmetric.
2. If one node is `NULL` and the other isn't, they are not symmetric.
3. If their values are different, return `false`.
4. Otherwise:
   - Compare the left child of the first tree with the right child of the second tree.
   - Compare the right child of the first tree with the left child of the second tree.

If both comparisons return true, the tree is symmetric.

## Algorithm

1. Start from the root.
2. Compare the left and right subtrees.
3. Recursively compare:
   - Left-Left with Right-Right
   - Left-Right with Right-Left
4. Return the final result.

## Example

Input:

        1
      /   \
     2     2
    / \   / \
   3  4  4  3

Comparisons:

- 2 ↔ 2 ✓
- 3 ↔ 3 ✓
- 4 ↔ 4 ✓

Output:

true