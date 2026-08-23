# Complexity Analysis

## Time Complexity

**O(n)**

- Every node is visited exactly once.

## Space Complexity

**O(h)**

- Recursive call stack stores at most one path from root to leaf.
- `h` is the height of the tree.
- Worst case (skewed tree): **O(n)**
- Best case (balanced tree): **O(log n)**

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(h)** |