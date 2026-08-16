Lowest Common Ancestor of a Binary Search Tree

Approach

We can solve this efficiently by using the BST property:

Left Subtree < Root < Right Subtree

At every node, compare the values of p and q with the current root.

Case 1: Both nodes are smaller than the root

If:

p < root
q < root

both nodes must be in the left subtree.

So, move left:

root = root->left;
Case 2: Both nodes are greater than the root

If:

p > root
q > root

both nodes must be in the right subtree.

So, move right:

root = root->right;
Case 3: The nodes are on different sides

If neither of the above conditions is true, then:

one node is on the left and the other is on the right, or
the current root is equal to p, or
the current root is equal to q.

Therefore, the current node is the Lowest Common Ancestor.

return root;