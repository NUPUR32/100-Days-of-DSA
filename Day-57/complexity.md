# Complexity Analysis

## Time Complexity

**O(n²)** (Worst Case)

- Every node is visited once.
- Finding the end of the right chain may take **O(n)** for each node in a skewed tree.

## Space Complexity

**O(h)**

- Recursive call stack uses **h** space, where **h** is the height of the tree.
- Worst Case: **O(n)**
- Balanced Tree: **O(log n)**

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n²)** |
| Space | **O(h)** |