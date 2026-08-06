#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int* ans = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }

        if (top != -1)
            ans[i] = stack[top] - i;
        else
            ans[i] = 0;

        stack[++top] = i;
    }

    *returnSize = n;
    free(stack);
    return ans;
}

int main() {
    int n;

    printf("Enter number of temperatures: ");
    scanf("%d", &n);

    int *temperatures = (int *)malloc(n * sizeof(int));

    printf("Enter %d temperatures:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temperatures[i]);
    }

    int returnSize;
    int *result = dailyTemperatures(temperatures, n, &returnSize);

    printf("\nOutput:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(temperatures);
    free(result);

    return 0;
}