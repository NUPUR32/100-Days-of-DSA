We use the Binary Search Tree (BST) property to search for the target value.

If the current node is NULL or its value equals val, return the current node.
If val is smaller than the current node's value, search in the left subtree.
If val is larger, search in the right subtree.

For val = 2:

2 < 4 → go left
2 == 2 → found, return this node

Result subtree:

    2
   / \
  1   3

If the value is not found (e.g., val = 5):

5 > 4 → go right
5 < 7 → go left
NULL  → return NULL

Time Complexity: O(h)
Space Complexity: O(h)

where h is the height of the BST.