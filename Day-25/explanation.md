Use two pointers: slow moves one step, fast moves two steps.


If they never meet, there is no cycle, so return None.


If they meet, reset slow to head.


Move both pointers one step at a time until they meet again.


The meeting point is the node where the cycle begins.
