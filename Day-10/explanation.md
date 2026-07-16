Find intersection of two arrays (with duplicates).

Approach 1 - Hash Map:
1. Count frequency of elements in nums1
2. Iterate through nums2
3. If element exists in map and count > 0, add to result
4. Decrement count

Approach 2 - Sorting:
1. Sort both arrays
2. Use two pointers
3. Add common elements

Key Points:
- Handle duplicates
- Can appear multiple times in result
