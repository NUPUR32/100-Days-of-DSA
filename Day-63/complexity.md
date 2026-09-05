
### `complexity.md`

```markdown
# Flood Fill - Complexity Analysis

## Time Complexity

**O(m × n)**

Where:

- `m` = number of rows
- `n` = number of columns

In the worst case, every pixel in the image has the same color as the starting pixel.

Therefore, DFS may visit every pixel once.

Hence:

```text
Time Complexity = O(m × n)

Space Complexity = O(m × n)