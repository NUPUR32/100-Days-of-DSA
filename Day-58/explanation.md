# 105. Construct Binary Tree from Preorder and Inorder Traversal

## Approach

The first element in the **preorder traversal** is always the root of the tree.

In the **inorder traversal**:

- Elements to the left of the root belong to the left subtree.
- Elements to the right of the root belong to the right subtree.

We recursively build the left and right subtrees.

## Algorithm

1. Take the current preorder element as the root.
2. Find its position in the inorder array.
3. Recursively build the left subtree.
4. Recursively build the right subtree.
5. Return the constructed root.

## Example

Input

Preorder = [3,9,20,15,7]

Inorder = [9,3,15,20,7]

Construction

```text
        3
       / \
      9   20
         /  \
        15   7
```

Output

```text
Preorder : 3 9 20 15 7
Inorder  : 9 3 15 20 7
```