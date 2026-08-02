#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Check if queue is empty
int isEmptyStack1() {
    return top1 == -1;
}

// Enqueue
void push(int x) {
    if (top1 == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    stack1[++top1] = x;
}

// Dequeue
int pop() {
    if (top1 == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }

    // Move all elements to stack2
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int removed = stack2[top2--];

    // Move back to stack1
    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return removed;
}

// Get front element
int peek() {
    if (top1 == -1) {
        printf("Queue is Empty!\n");
        return -1;
    }

    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }

    int front = stack2[top2];

    while (top2 != -1) {
        stack1[++top1] = stack2[top2--];
    }

    return front;
}

// Check if queue is empty
int empty() {
    return top1 == -1;
}

int main() {
    // Enqueue elements
    push(10);
    push(20);
    push(30);

    printf("Front element: %d\n", peek());

    printf("Removed: %d\n", pop());
    printf("Removed: %d\n", pop());

    push(40);

    printf("Front element: %d\n", peek());

    while (!empty()) {
        printf("Dequeued: %d\n", pop());
    }

    return 0;
}