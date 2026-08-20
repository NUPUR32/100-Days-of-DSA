# LeetCode 102 - Binary Tree Level Order Traversal

## Approach

We use **Breadth-First Search (BFS)** to traverse the binary tree level by level.

A **queue** is used to keep track of the nodes that need to be visited.

### Algorithm

1. If the root is `NULL`, return an empty result.
2. Create a queue and insert the root node.
3. While the queue is not empty:
   - Count the number of nodes currently in the queue. This represents one level of the tree.
   - Create an array to store the values of the current level.
   - Remove each node from the queue.
   - Store its value in the current level array.
   - Insert its left child into the queue if it exists.
   - Insert its right child into the queue if it exists.
4. Store the current level array in the final result.
5. Repeat until the queue becomes empty.

Finally, return the 2D array containing all levels.

---

## Example

Input:

        3
       / \
      9   20
         /  \
        15   7

### Initial Queue

```
[3]
```

### Level 1

- Remove 3
- Store value: `[3]`
- Add children: 9, 20

Queue:

```
[9, 20]
```

Result:

```
[[3]]
```

---

### Level 2

- Remove 9
- Store value: `[9]`

- Remove 20
- Store value: `[9, 20]`

- Add children: 15, 7

Queue:

```
[15, 7]
```

Result:

```
[[3], [9,20]]
```

---

### Level 3

- Remove 15
- Remove 7

Queue becomes empty.

Final Result:

```
[[3], [9,20], [15,7]]
```

---

## Why BFS?

Breadth-First Search visits nodes **level by level**, making it the ideal approach for level-order traversal.

The queue follows the **First In First Out (FIFO)** principle, ensuring that nodes are processed in the correct order.