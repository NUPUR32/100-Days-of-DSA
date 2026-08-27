# Number of Provinces

## Idea

Treat the cities as vertices of an undirected graph.

- Each city is a node.
- A value of `1` in the adjacency matrix indicates a direct connection.
- Use DFS to visit every city connected to the current city.

Each DFS traversal visits exactly one connected component, which represents one province.

## Algorithm

1. Create a visited array.
2. Traverse every city.
3. If a city is not visited:
   - Run DFS from that city.
   - Mark all reachable cities as visited.
   - Increase the province count.
4. Return the province count.

## Example

Input:

1 1 0

1 1 0

0 0 1

DFS from city 0 visits {0,1} → Province 1

DFS from city 2 visits {2} → Province 2

Output:

2

## Complexity

- Time: **O(n²)**
- Space: **O(n)**