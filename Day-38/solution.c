#include <stdio.h>

#define MAX 10000

int deque[MAX];
int front = 0, rear = -1;

int isEmpty() {
    return front > rear;
}

void popFront() {
    front++;
}

void popBack() {
    rear--;
}

void pushBack(int x) {
    deque[++rear] = x;
}

int getFront() {
    return deque[front];
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Use MAX instead of Variable Length Array if your compiler doesn't support C99
    int nums[MAX];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter window size: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid window size!\n");
        return 1;
    }

    int result[MAX];
    int resSize = 0;

    // Reset deque pointers
    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove indices outside the current window
        if (!isEmpty() && getFront() <= i - k)
            popFront();

        // Remove smaller elements
        while (!isEmpty() && nums[deque[rear]] < nums[i])
            popBack();

        pushBack(i);

        // Store maximum of current window
        if (i >= k - 1)
            result[resSize++] = nums[getFront()];
    }

    printf("\nMaximums of each window:\n");
    for (int i = 0; i < resSize; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}