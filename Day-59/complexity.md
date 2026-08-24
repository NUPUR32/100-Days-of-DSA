# Complexity Analysis

## Time Complexity

- Finding the root in the inorder array takes **O(n)** for each recursive call.
- In the worst case, this happens for every node.

**Overall Time Complexity:** **O(n²)**

> Note: Using a HashMap to store inorder indices can reduce the time complexity to **O(n)**.

---

## Space Complexity

- Recursive call stack stores at most **h** nodes.

Worst case (skewed tree):

**O(n)**

Balanced tree:

**O(log n)**

Additional memory for tree nodes is required to store the output tree.

**Overall Auxiliary Space:** **O(h)**

where **h** is the height of the tree.