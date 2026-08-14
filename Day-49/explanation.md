We use the Binary Search Tree (BST) property to insert the new value.

If val is smaller than the current node, move to the left.
If val is greater, move to the right.
When we reach NULL, create and insert the new node.
Return the root after insertion.

For val = 5:

5 > 4 → go right
5 < 7 → go left
NULL  → insert 5

Result:

        4
       / \
      2   7
     / \  /
    1   3 5

Time Complexity: O(h)
Space Complexity: O(h)

where h is the height of the BST.