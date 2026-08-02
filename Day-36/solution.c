#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* q;
    int f;
    int r;
    int n;
} MyCircularDeque;

// Function Prototypes
MyCircularDeque* myCircularDequeCreate(int k);
int myCircularDequeInsertFront(MyCircularDeque* obj, int value);
int myCircularDequeInsertLast(MyCircularDeque* obj, int value);
int myCircularDequeDeleteFront(MyCircularDeque* obj);
int myCircularDequeDeleteLast(MyCircularDeque* obj);
int myCircularDequeGetFront(MyCircularDeque* obj);
int myCircularDequeGetRear(MyCircularDeque* obj);
int myCircularDequeIsEmpty(MyCircularDeque* obj);
int myCircularDequeIsFull(MyCircularDeque* obj);
void myCircularDequeFree(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->n = k + 1;
    obj->q = (int*)malloc(sizeof(int) * obj->n);
    obj->f = 0;
    obj->r = 0;
    return obj;
}

int myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
        return 0;

    obj->f = (obj->f - 1 + obj->n) % obj->n;
    obj->q[obj->f] = value;
    return 1;
}

int myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
        return 0;

    obj->q[obj->r] = value;
    obj->r = (obj->r + 1) % obj->n;
    return 1;
}

int myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return 0;

    obj->f = (obj->f + 1) % obj->n;
    return 1;
}

int myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return 0;

    obj->r = (obj->r - 1 + obj->n) % obj->n;
    return 1;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;

    return obj->q[obj->f];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;

    return obj->q[(obj->r - 1 + obj->n) % obj->n];
}

int myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->f == obj->r;
}

int myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->r + 1) % obj->n == obj->f;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->q);
    free(obj);
}

int main() {
    MyCircularDeque* deque = myCircularDequeCreate(3);

    printf("InsertLast(1): %d\n", myCircularDequeInsertLast(deque, 1));
    printf("InsertLast(2): %d\n", myCircularDequeInsertLast(deque, 2));
    printf("InsertFront(3): %d\n", myCircularDequeInsertFront(deque, 3));
    printf("InsertFront(4): %d\n", myCircularDequeInsertFront(deque, 4));

    printf("Rear: %d\n", myCircularDequeGetRear(deque));
    printf("IsFull: %d\n", myCircularDequeIsFull(deque));

    printf("DeleteLast: %d\n", myCircularDequeDeleteLast(deque));
    printf("InsertFront(4): %d\n", myCircularDequeInsertFront(deque, 4));

    printf("Front: %d\n", myCircularDequeGetFront(deque));
    printf("Rear: %d\n", myCircularDequeGetRear(deque));

    myCircularDequeFree(deque);
    return 0;
}