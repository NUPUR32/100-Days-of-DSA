# Complexity Analysis

## Time Complexity

- For every city, we may scan all other cities in the adjacency matrix.
- Hence, the total time complexity is:

**O(n²)**

where `n` is the number of cities.

---

## Space Complexity

- Visited array stores one value for each city.
- DFS recursion stack can go up to `n` in the worst case.

**O(n)**

---

## Summary

| Complexity | Value |
|------------|-------|
| Time | **O(n²)** |
| Space | **O(n)** |