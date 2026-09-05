# Flood Fill - Explanation

## Problem

Given an `m x n` image represented as a 2D integer matrix, perform a flood fill starting from the pixel `(sr, sc)`.

All pixels connected horizontally or vertically to the starting pixel and having the same original color should be changed to the new `color`.

---

## Approach: Depth-First Search (DFS)

We use **DFS (Depth-First Search)** to visit all connected pixels having the same color as the starting pixel.

### Steps

1. Find the original color at image[sr][sc].
2. If original color == new color:
      return.
3. Start DFS from (sr, sc).
4. For each pixel:
      a. Check boundaries.
      b. Check if pixel has original color.
      c. Change it to new color.
      d. Visit Up, Down, Left and Right.
5. Return the modified image.