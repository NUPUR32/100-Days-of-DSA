The KthLargest structure maintains the kth largest element in a stream of integers using a Min-Heap.

Intuition:
- To efficiently track the kth largest element, we only need the largest k elements seen so far.
- A Min-Heap of size k is ideal because the smallest element in the heap represents the kth largest overall.

Approach:
- Use a Min-Heap implemented via an array.
- While initializing, insert elements into the heap and if the size exceeds k, remove the minimum.
- When adding a new element, insert it into the heap and again ensure the heap size does not exceed k.
- The root of the heap always gives the kth largest element.

Heap Operations:
- Insert: O(log k)
- Remove Min: O(log k)

This approach is efficient for continuous streams of data.