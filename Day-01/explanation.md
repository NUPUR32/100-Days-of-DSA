Find two numbers that add up to target using a brute-force approach.

Approach:
1. Use two nested loops to check all possible pairs
2. Fix the first number using the outer loop
3. For each fixed number, check the remaining numbers using the inner loop
4. If nums[i] + nums[j] equals target, return their indices

Why it works:
- All possible pairs are checked
- No extra data structure is used
- Guaranteed to find the correct pair if it exists
