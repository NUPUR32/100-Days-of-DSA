# Complexity Analysis

## Time Complexity

**O(n)**

Where `n` is the total number of nodes in the binary tree.

In the worst case, the algorithm visits every node once while searching for `p` and `q`.

Therefore:

```text
Time Complexity = O(n)
```

---

## Space Complexity

**O(h)**

Where `h` is the height of the binary tree.

The extra space is used by the recursive call stack.

### Balanced Binary Tree

For a balanced binary tree:

```text
h = log n
```

Therefore:

```text
Space Complexity = O(log n)
```

### Skewed Binary Tree

For a completely skewed binary tree:

```text
h = n
```

Therefore:

```text
Space Complexity = O(n)
```

---

## Final Complexity

| Complexity          | Result     |
| ------------------- | ---------- |
| Time                | `O(n)`     |
| Space               | `O(h)`     |
| Balanced Tree Space | `O(log n)` |
| Worst-Case Space    | `O(n)`     |
