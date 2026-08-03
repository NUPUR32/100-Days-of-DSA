#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));

    if (h == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    h->heap = (int*)malloc(sizeof(int) * capacity);

    if (h->heap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    h->size = 0;
    h->capacity = capacity;

    return h;
}

void heapifyUp(MinHeap* h, int index) {
    while (index > 0 && h->heap[(index - 1) / 2] > h->heap[index]) {
        swap(&h->heap[index], &h->heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* h, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < h->size && h->heap[left] < h->heap[smallest])
            smallest = left;

        if (right < h->size && h->heap[right] < h->heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&h->heap[index], &h->heap[smallest]);
        index = smallest;
    }
}

void insertHeap(MinHeap* h, int val) {
    if (h->size < h->capacity) {
        h->heap[h->size] = val;
        h->size++;
        heapifyUp(h, h->size - 1);
    }
    else if (val > h->heap[0]) {
        h->heap[0] = val;
        heapifyDown(h, 0);
    }
}

int getMin(MinHeap* h) {
    if (h->size == 0)
        return -1;
    return h->heap[0];
}

typedef struct {
    MinHeap *heap;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));

    if (obj == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    obj->heap = createMinHeap(k);

    for (int i = 0; i < numsSize; i++) {
        insertHeap(obj->heap, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    insertHeap(obj->heap, val);
    return getMin(obj->heap);
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap->heap);
    free(obj->heap);
    free(obj);
}

int main() {
    int nums[] = {4, 5, 8, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    KthLargest *obj = kthLargestCreate(k, nums, numsSize);

    printf("%d\n", kthLargestAdd(obj, 3));   // 4
    printf("%d\n", kthLargestAdd(obj, 5));   // 5
    printf("%d\n", kthLargestAdd(obj, 10));  // 5
    printf("%d\n", kthLargestAdd(obj, 9));   // 8
    printf("%d\n", kthLargestAdd(obj, 4));   // 8

    kthLargestFree(obj);

    return 0;
}