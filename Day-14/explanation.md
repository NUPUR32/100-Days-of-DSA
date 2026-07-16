Rotate n×n matrix 90 degrees clockwise in-place.

Approach:
1. Transpose the matrix (swap mat[i][j] with mat[j][i])
2. Reverse each row
3. Result is 90-degree clockwise rotation

Alternative: Rotate layer by layer

Key Points:
- In-place rotation required
- Transpose + reverse = rotate 90°
- Must handle square matrix only
