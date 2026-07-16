Set entire row and column to 0 if element is 0.

Approach (O(1) space):
1. Use first row and column as markers
2. Scan matrix, mark first row/column if 0 found
3. Use markers to set zeros
4. Handle first row/column separately

Key Points:
- Must modify in-place
- O(1) space solution uses matrix itself
- Process from bottom-right to preserve markers
