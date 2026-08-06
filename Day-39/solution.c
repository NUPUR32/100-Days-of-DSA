#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

/* Hash table node */
typedef struct {
    int key;
    int freq;
} HashNode;

HashNode hash[MAX];
int hashSize = 0;

int findIndex(int key) {
    for (int i = 0; i < hashSize; i++) {
        if (hash[i].key == key)
            return i;
    }
    return -1;
}

/* Min Heap node */
typedef struct {
    int freq;
    int val;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].freq > heap[i].freq) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else
            break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < heapSize && heap[l].freq < heap[smallest].freq)
            smallest = l;

        if (r < heapSize && heap[r].freq < heap[smallest].freq)
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else
            break;
    }
}

void pushHeap(int freq, int val, int k) {
    heap[heapSize].freq = freq;
    heap[heapSize].val = val;
    heapSize++;

    heapifyUp(heapSize - 1);

    if (heapSize > k) {
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(0);
    }
}

int main() {
    int n, k;
    int nums[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid value of k\n");
        return 1;
    }

    /* Count frequencies */
    for (int i = 0; i < n; i++) {
        int idx = findIndex(nums[i]);
        if (idx == -1) {
            hash[hashSize].key = nums[i];
            hash[hashSize].freq = 1;
            hashSize++;
        } else {
            hash[idx].freq++;
        }
    }

    /* Build heap */
    for (int i = 0; i < hashSize; i++)
        pushHeap(hash[i].freq, hash[i].key, k);

    printf("\nTop %d frequent elements are:\n", k);

    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].val);

    printf("\n");

    return 0;
}