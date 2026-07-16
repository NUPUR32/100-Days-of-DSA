Maximum Sum Circular Subarray using Kadane’s Algorithm.

Approach:
1. Use Kadane’s algorithm to find maximum subarray sum (non-circular).
2. Use modified Kadane’s to find minimum subarray sum.
3. Calculate total array sum.
4. Answer = max(maxSub, totalSum - minSub).
5. If all elements are negative (totalSum == minSub), return maxSub.
