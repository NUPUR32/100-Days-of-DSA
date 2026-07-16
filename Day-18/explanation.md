Calculate product of all elements except self without division.

Approach:
1. Calculate prefix products (product of all elements before i)
2. Calculate suffix products (product of all elements after i)
3. result[i] = prefix[i] * suffix[i]

Optimized: Use result array to store prefix, then multiply by suffix in reverse

Key Points:
- Cannot use division
- O(n) time, O(1) extra space (output doesn't count)
- Two passes through array
