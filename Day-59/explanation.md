# Construct Binary Tree from Inorder and Postorder Traversal

## Approach

1. The last element of the postorder traversal is always the root of the current subtree.
2. Find this root in the inorder traversal.
3. Elements to the left of the root belong to the left subtree.
4. Elements to the right belong to the right subtree.
5. Recursively build:
   - Left subtree
   - Right subtree
6. Return the constructed root.

## Example

Input:

Inorder:
9 3 15 20 7

Postorder:
9 15 7 20 3

Root = 3

Left Inorder:
9

Right Inorder:
15 20 7

Repeat the same process recursively until the tree is built.

Constructed Tree:

        3
       / \
      9   20
         /  \
        15   7