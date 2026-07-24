Remove cycle from linked list:

1. Detect cycle using Floyd's algorithm
2. Find start of cycle
3. Find node just before start
4. Set its next to NULL

Key Points:
- First detect if cycle exists
- Move one pointer to head after detection
- Move both one step until they meet (cycle start)
- Remove by setting next to NULL