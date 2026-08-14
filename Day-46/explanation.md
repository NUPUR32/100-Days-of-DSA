We use Breadth-First Search (BFS) with a queue.

BFS is suitable for this problem because it visits the nodes of a binary tree level by level.

Steps:-

1.If the root is NULL, return an empty result.
2.Create a queue and insert the root node.
3.While the queue is not empty:
-Find the number of nodes in the current level.
-Create an array to store the values of that level.
-Remove each node from the queue.
-Store its value in the current level array.
-Add its left child to the queue if it exists.
-Add its right child to the queue if it exists.
4.Store the completed level in the result.
5.Repeat until the queue becomes empty.
6.Return the result.
