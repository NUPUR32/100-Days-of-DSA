# Complexity Analysis

## Time Complexity
- Each node is visited exactly once.
- Therefore, the time complexity is:

**O(n)**

where `n` is the number of nodes in the binary tree.

---

## Space Complexity
- Recursive DFS uses the call stack.
- Maximum recursion depth equals the tree height.

**O(h)**

where:
- `h` = height of the tree.
- Worst case (skewed tree): **O(n)**
- Best case (balanced tree): **O(log n)**

---

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(h)** |