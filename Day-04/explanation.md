Remove all instances of val in-place using two pointers.

Approach:
1. Use slow pointer to track position to write
2. Fast pointer scans through array
3. Copy non-val elements to slow pointer position
4. Return new length

Key Points:
- In-place modification
- Order of elements can change
- Return new array length
