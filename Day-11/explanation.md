Approach:

1. Find number of rows m and columns n
2. Create a new matrix transpose of size n × m
3. Traverse the original matrix using two nested loops:
- Outer loop for rows (i)
- Inner loop for columns (j)
4. Assign:
transpose[j][i] = matrix[i][j]
5. Return the transposed matrix

Key Points:
- Rows become columns and columns become rows
- Works for rectangular matrices as well
- Uses extra space for the transposed matrix
