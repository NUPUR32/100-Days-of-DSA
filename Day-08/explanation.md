Check if n is a power of 2.

Approach 1 - Bit Manipulation:
1. Power of 2 has exactly one bit set
2. Use n & (n-1) == 0 trick
3. Also check n > 0

Approach 2 - Recursive Division:
1. Keep dividing by 2
2. Check if remainder is 0
3. Final result should be 1

Key Points:
- Bit manipulation is O(1)
- Powers of 2: 1, 2, 4, 8, 16, ...
