# Keys and Rooms

## Idea

Treat each room as a node in a graph.

- Room `0` is already unlocked.
- Keys inside a room represent edges to other rooms.
- Use DFS to visit every reachable room.
- If all rooms are visited, return `true`; otherwise, return `false`.

## Algorithm

1. Create a visited array.
2. Start DFS from room `0`.
3. For every key in the current room:
   - If the corresponding room is not visited, recursively visit it.
4. After DFS, check whether every room is visited.
5. Return the result.

## Example

Input:

Room 0 → {1}

Room 1 → {2}

Room 2 → {3}

Room 3 → {}

Traversal:

0 → 1 → 2 → 3

All rooms are visited.

Output:

true

## Complexity

- Time: **O(n + e)**
- Space: **O(n)**

where:
- `n` = number of rooms
- `e` = total number of keys