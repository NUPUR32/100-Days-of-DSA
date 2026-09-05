1. Create a queue.
2. Traverse the entire grid.
3. Add all rotten oranges to the queue.
4. Count all fresh oranges.
5. If fresh == 0, return 0.
6. Start Multi-Source BFS.
7. For every BFS level:
      a. Process all currently rotten oranges.
      b. Check their four neighbors.
      c. Convert neighboring fresh oranges to rotten.
      d. Add newly rotten oranges to the queue.
      e. Decrease fresh count.
      f. Increase minutes.
8. If fresh > 0 after BFS:
      return -1.
9. Otherwise:
      return minutes.