Merge nums2 into nums1 (which has enough space) in-place.

Approach:
1. Start from the end of both arrays
2. Compare elements and place larger one at end of nums1
3. Move pointers backward
4. Copy remaining elements from nums2 if any

Key Points:
- Work backwards to avoid overwriting
- nums1 has space for both arrays
- In-place solution
