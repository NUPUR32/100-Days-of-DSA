# Complexity Analysis

## Time Complexity

Each node is visited exactly once during the traversal.

Therefore,

**Time Complexity:** **O(n)**

where **n** is the total number of nodes in the binary tree.

---

## Space Complexity

The queue stores the nodes of one level at a time.

In the worst case (for a complete binary tree), the queue can contain nearly **n/2** nodes.

Therefore,

**Space Complexity:** **O(n)**

---

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(n)** |

---

## Key Points

- **Traversal Technique:** Breadth-First Search (BFS)
- **Data Structure Used:** Queue
- **Nodes Visited:** Exactly once
- **Suitable For:** Level-by-level traversal of a binary tree