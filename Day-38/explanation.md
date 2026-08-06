Sliding Window Maximum using Monotonic Deque (C Implementation).

Approach:
- Use a deque that stores indices of elements.
- The deque is maintained in decreasing order of values.
- Front of deque always stores the index of the maximum element of the current window.

Steps:
1. Remove indices from the front that are out of the current window (i - k).
2. Remove indices from the back whose corresponding values are smaller than the current element, as they cannot be maximum anymore.
3. Insert the current index at the back.
4. Once the first window is completed (i >= k - 1), store the value at the front index as the maximum.

This ensures each element is pushed and popped at most once.