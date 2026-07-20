/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node
    struct ListNode dummy;
    dummy.next = head;

    // Pointer to traverse the list
    struct ListNode *curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            // Remove the node
            curr->next = curr->next->next;
        } else {
            // Move to next node
            curr = curr->next;
        }
    }

    return dummy.next;
}
