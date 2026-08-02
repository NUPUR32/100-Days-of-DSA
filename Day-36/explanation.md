Implement a Circular Deque using an array.

Approach:
- Use an array of size k+1 to distinguish full and empty states.
- Maintain two pointers: front (f) and rear (r).
- Perform insert/delete from both ends using modulo arithmetic.
- All operations run in constant time.