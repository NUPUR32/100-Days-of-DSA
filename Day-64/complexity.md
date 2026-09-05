
### `complexity.md`

```markdown
# 994. Rotting Oranges - Complexity Analysis

## Time Complexity

### O(m × n)

Where:

- `m` = number of rows
- `n` = number of columns

First, we traverse the complete grid to:

- Find all initially rotten oranges.
- Count all fresh oranges.

This requires:

```text
Time  : O(m × n)
Space : O(m × n)