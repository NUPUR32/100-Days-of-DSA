Return all elements in spiral order.

Approach:
1. Use four boundary variables
2. Traverse in order: right, down, left, up
3. Shrink boundaries after each direction
4. Continue until all elements visited

Key Points:
- Handle edge cases (empty, single row/column)
- Check boundaries before each traversal
- Use dynamic array to store result
