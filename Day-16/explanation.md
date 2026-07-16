Rotate array to right by k steps.

Approach (Reverse Method):
1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining n-k elements

Alternative: Use extra space to copy

Key Points:
- k can be > n, use k % n
- In-place solution preferred
- Three reverses achieve rotation
