Approach:

A matrix is Toeplitz if:

matrix[i][j] = matrix[i - 1][j - 1]

for all valid i > 0 and j > 0.

Steps:
1. Start checking from cell (1, 1) since (0, 0) has no top-left neighbor
2. Traverse the matrix using nested loops
3. For every cell (i, j), compare it with (i - 1, j - 1)
4. If any mismatch is found, return false
5. If all diagonal comparisons pass, return true

Key Points:
- Each diagonal from top-left to bottom-right must have same elements
- Works for rectangular matrices
- No extra space required
