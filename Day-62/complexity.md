# Complexity Analysis

## Time Complexity

- Every room is visited once.
- Every key is processed exactly once.

Therefore,

**O(n + e)**

where:
- `n` = number of rooms
- `e` = total number of keys.

---

## Space Complexity

- Visited array stores one value per room.
- DFS recursion stack can grow up to `n` in the worst case.

**O(n)**

---

## Summary

| Complexity | Value |
|-----------|-------|
| Time | **O(n + e)** |
| Space | **O(n)** |
```