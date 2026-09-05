# Undirected Graph Cycle - Explanation

## Problem

Given an undirected graph with:

- `V` vertices
- `E` edges

we need to determine whether the graph contains a **cycle**.

The graph may also contain multiple disconnected components.

---

## Approach: DFS with Parent Tracking

We use **Depth-First Search (DFS)** to traverse the graph.

While performing DFS, we maintain:

- A `visited[]` array to track visited vertices.
- A `parent` value to remember the vertex from which the current vertex was reached.

The main idea is:

> If we find an already visited neighbor that is not the parent of the current vertex, then a cycle exists.

---

## Why Do We Need the Parent?

Consider:

```text
0 ----- 1