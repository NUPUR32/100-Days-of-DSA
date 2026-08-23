# Complexity Analysis

## Time Complexity

**O(n²)** (Worst Case)

- Building the tree visits each node once.
- Searching for the root in the inorder array takes **O(n)** each time.

**Optimized Approach:** Using a Hash Map to store inorder indices reduces the time complexity to **O(n)**.

## Space Complexity

**O(h)**

- Recursive call stack stores at most **h** nodes.
- Worst Case (Skewed Tree): **O(n)**
- Balanced Tree: **O(log n)**

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n²)** |
| Space | **O(h)** |