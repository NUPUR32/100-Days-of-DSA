Create a dummy node pointing to the head to handle

deletion of the first node easily.

Use a pointer curr starting

from the dummy node.

Traverse the list while curr->next 

is not NULL.

If curr->next->val == val, skip that node by setting

curr->next = curr->next->next; otherwise, move curr forward.

Return dummy.next, which is the head of the

updated linked list.
