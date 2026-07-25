#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* secondHalf = reverseList(slow->next);

    // Compare
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;
    bool result = true;

    while (p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return result;
}

/* --- helpers just for the demo below --- */

struct ListNode* makeList(int *vals, int n) {
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = vals[i];
        node->next = NULL;
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void freeList(struct ListNode *head) {
    while (head) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    int a[] = {1, 2, 3, 2, 1};
    int b[] = {1, 2, 3, 4};

    struct ListNode *list1 = makeList(a, 5);
    struct ListNode *list2 = makeList(b, 4);

    printf("[1,2,3,2,1] is palindrome: %s\n", isPalindrome(list1) ? "true" : "false");
    printf("[1,2,3,4]   is palindrome: %s\n", isPalindrome(list2) ? "true" : "false");

    freeList(list1);
    freeList(list2);
    return 0;
}