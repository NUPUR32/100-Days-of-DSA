# LeetCode 199 - Binary Tree Right Side View

## Approach

We use **Breadth-First Search (BFS)** with a queue to traverse the binary tree level by level.

At each level, the **last node visited** is the node visible from the right side. Therefore, we store the value of the last node of every level in the result array.

---

## Algorithm

1. If the root is `NULL`, return an empty array.
2. Create a queue and insert the root node.
3. While the queue is not empty:
   - Find the number of nodes in the current level (`levelSize`).
   - Process all nodes of the current level.
   - Remove each node from the queue.
   - If the current node is the last node of the level (`i == levelSize - 1`), store its value in the result array.
   - Insert the left child into the queue if it exists.
   - Insert the right child into the queue if it exists.
4. Repeat until the queue becomes empty.
5. Return the result array containing the right side view.

---

## Example

Input:

```
        1
       / \
      2   3
       \   \
        5   4
```

### Level 1

Queue:

```
[1]
```

Visible node:

```
1
```

Result:

```
[1]
```

---

### Level 2

Queue:

```
[2, 3]
```

The last node processed is **3**, which is visible from the right side.

Result:

```
[1, 3]
```

---

### Level 3

Queue:

```
[5, 4]
```

The last node processed is **4**, which is visible from the right side.

Result:

```
[1, 3, 4]
```

---

## Why BFS?

Breadth-First Search processes nodes **level by level**.

Since the last node processed at each level is the rightmost node, it represents the node visible from the right side. This allows us to obtain the answer in a single traversal without any extra processing.