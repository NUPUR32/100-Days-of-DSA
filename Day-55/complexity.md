# Complexity Analysis

## Time Complexity

The algorithm performs a **Breadth-First Search (BFS)** traversal of the binary tree.

- Each node is visited exactly **once**.
- For every node, we perform constant-time operations:
- Remove it from the queue.
- Check whether it is the last node of the current level.
- Insert its left and right children into the queue (if they exist).

Therefore, the overall time complexity is:

**Time Complexity:** **O(n)**

where **n** is the total number of nodes in the binary tree.

---

## Space Complexity

The algorithm uses a queue to store nodes during the level-order traversal.

- In the worst case (a complete binary tree), the queue can contain up to one entire level of nodes, which is **O(n)**.
- The result array stores one value for each level, which is at most **O(n)** in the worst case.

Therefore, the overall space complexity is:

**Space Complexity:** **O(n)**

---

## Summary

| Complexity | Value |
|------------|-------|
| **Time Complexity** | **O(n)** |
| **Space Complexity** | **O(n)** |

---

## Key Points

- **Traversal Technique:** Breadth-First Search (BFS)
- **Data Structure Used:** Queue
- **Nodes Processed:** Each node is visited exactly once.
- **Visible Node:** The last node at each level is added to the result, representing the right-side view.