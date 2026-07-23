#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    obj->size++;
}

int main() {
    MyLinkedList* list = myLinkedListCreate();

    myLinkedListAddAtHead(list, 10);
    myLinkedListAddAtTail(list, 20);
    myLinkedListAddAtTail(list, 30);

    printf("%d\n", myLinkedListGet(list, 0)); // 10
    printf("%d\n", myLinkedListGet(list, 1)); // 20
    printf("%d\n", myLinkedListGet(list, 2)); // 30

    return 0;
}