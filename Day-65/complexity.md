
### `complexity.md`

```markdown
# Undirected Graph Cycle - Complexity Analysis

## Time Complexity

### O(V + E)

Where:

- `V` = number of vertices
- `E` = number of edges

---

## Adjacency List Creation

We process every edge once while constructing the graph.

Since the graph is undirected, each edge is stored twice:

```text
u -> v
v -> u
Time Complexity  : O(V + E)
Space Complexity : O(V + E)
Auxiliary Space  : O(V)