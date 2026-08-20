# LeetCode 103 - Binary Tree Zigzag Level Order Traversal

## Approach

We use **Breadth-First Search (BFS)** with a queue to traverse the binary tree level by level.

The only difference from the normal level-order traversal is that the direction of storing node values alternates after every level.

- First level → Left to Right
- Second level → Right to Left
- Third level → Left to Right
- and so on...

Instead of reversing the array after each level, we directly place each node's value at the correct position using an index.

---

## Algorithm

1. If the root is `NULL`, return an empty result.
2. Create a queue and insert the root node.
3. Maintain a boolean variable `leftToRight`, initially `true`.
4. While the queue is not empty:
   - Find the number of nodes in the current level.
   - Allocate an array for that level.
   - Remove each node from the queue.
   - If traversing left to right, store the value at index `i`.
   - Otherwise, store the value at index `levelSize - 1 - i`.
   - Insert the left and right children into the queue.
5. Toggle `leftToRight` after each level.
6. Return the final 2D array.

---

## Example

Input:

        3
       / \
      9   20
         /  \
        15   7

### Level 1 (Left → Right)

Queue:

```
[3]
```

Store:

```
[3]
```

Result:

```
[[3]]
```

---

### Level 2 (Right → Left)

Queue:

```
[9,20]
```

Store values in reverse positions.

Instead of

```
[9,20]
```

Store as

```
[20,9]
```

Result:

```
[[3],[20,9]]
```

---

### Level 3 (Left → Right)

Queue:

```
[15,7]
```

Store normally.

```
[15,7]
```

Final Result:

```
[[3],[20,9],[15,7]]
```

---

## Why BFS?

Breadth-First Search naturally visits nodes one level at a time.

By changing only the insertion index for each level, we achieve the zigzag traversal without performing any extra reverse operation.