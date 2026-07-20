Detect cycle using Floyd's algorithm (slow-fast pointers):

1. Use two pointers: slow moves 1 step, fast moves 2 steps
2. If fast meets slow, cycle exists
3. If fast reaches NULL, no cycle

Key Points:
- Also called tortoise and hare algorithm
- O(n) time, O(1) space
- Fast pointer will catch slow if cycle exists
