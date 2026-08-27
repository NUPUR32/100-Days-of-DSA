# Binary Tree Cameras

## Idea

Use a greedy strategy with postorder traversal (Left → Right → Root).

Each node can be in one of three states:

- **0** → Needs Camera
- **1** → Has Camera
- **2** → Covered

## Algorithm

1. Traverse the tree using postorder DFS.
2. If any child needs a camera, place a camera at the current node.
3. If any child has a camera, the current node is already covered.
4. Otherwise, the current node needs a camera.
5. After DFS, if the root still needs a camera, place one final camera.

## Why Postorder?

Children are processed before the parent, allowing the parent to decide whether a camera is necessary based on the children's states.

