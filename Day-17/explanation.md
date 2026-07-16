Find maximum sum contiguous subarray (Kadane's Algorithm).

Approach:
1. Keep track of current sum and max sum
2. Add current element to current sum
3. If current sum < 0, reset to current element
4. Update max sum at each step

Key Points:
- Dynamic programming approach
- Linear time solution
- Handle all negative numbers case
