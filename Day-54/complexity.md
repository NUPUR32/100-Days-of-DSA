# Complexity Analysis

## Time Complexity

Each node in the binary tree is visited exactly once during the Breadth-First Search (BFS).

For every node, we perform the following operations:
- Remove the node from the queue.
- Store its value in the current level array.
- Insert its left and right children into the queue (if they exist).

Since every node is processed only one time, the overall time complexity is:

**Time Complexity:** **O(n)**

where **n** is the total number of nodes in the binary tree.

---

## Space Complexity

The algorithm uses:

1. **Queue:** Stores nodes level by level during BFS. In the worst case (complete binary tree), the queue can hold approximately **n/2** nodes.
2. **Result Array:** Stores all node values, requiring space proportional to the number of nodes.

Therefore, the overall auxiliary space required is:

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
- **Traversal Pattern:** Alternates between left-to-right and right-to-left at each level.
- **Optimization:** Instead of reversing each level after traversal, the algorithm directly places node values at the correct index, maintaining an overall **O(n)** time complexity.