#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Reverse a linked list
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

// Add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;
    }

    return reverseList(dummy.next);
}

// Create linked list from array
struct ListNode* createList(int arr[], int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Free memory
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Number 7243
    int arr1[] = {7, 2, 4, 3};

    // Number 564
    int arr2[] = {5, 6, 4};

    struct ListNode* l1 = createList(arr1, 4);
    struct ListNode* l2 = createList(arr2, 3);

    printf("First Number : ");
    printList(l1);

    printf("Second Number: ");
    printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result       : ");
    printList(result);

    freeList(result);

    return 0;
}