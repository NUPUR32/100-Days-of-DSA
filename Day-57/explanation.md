# 57. Flatten Binary Tree to Linked List

## Approach

The tree must be converted into a linked list following **preorder traversal (Root → Left → Right)**.

We recursively flatten the left and right subtrees.

Steps:

1. Flatten the left subtree.
2. Flatten the right subtree.
3. Store pointers to the left and right subtrees.
4. Move the left subtree to the right side.
5. Set the left pointer to `NULL`.
6. Traverse to the end of the new right chain.
7. Attach the original right subtree.

This modifies the tree in-place.

## Algorithm

1. If the node is `NULL`, return.
2. Flatten the left subtree.
3. Flatten the right subtree.
4. Save the left and right subtrees.
5. Make the left subtree the new right subtree.
6. Move to the end of the right chain.
7. Attach the original right subtree.

## Example

Input

        1
      /   \
     2     5
    / \     \
   3   4     6

After Flatten

1 → 2 → 3 → 4 → 5 → 6

(All left pointers become `NULL`.)