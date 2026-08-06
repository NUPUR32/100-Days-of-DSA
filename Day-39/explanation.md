Find the k most frequent elements in an array.

Approach:
- Use a hash table to count frequency of each element in O(n).

- Use a min-heap (priority queue) of size k to keep only top k frequent elements.

- If heap size exceeds k, remove the element with smallest frequency.

- Finally, heap contains k most frequent elements.