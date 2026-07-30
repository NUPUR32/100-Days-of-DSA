#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }
        else if (strcmp(tokens[i], "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }
        else if (strcmp(tokens[i], "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }
        else if (strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;   // Truncates toward zero
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}

int main() {
    // Example 1
    char *tokens1[] = {"2", "1", "+", "3", "*"};
    int size1 = sizeof(tokens1) / sizeof(tokens1[0]);
    printf("Output 1: %d\n", evalRPN(tokens1, size1));

    // Example 2
    char *tokens2[] = {"4", "13", "5", "/", "+"};
    int size2 = sizeof(tokens2) / sizeof(tokens2[0]);
    printf("Output 2: %d\n", evalRPN(tokens2, size2));

    // Example 3
    char *tokens3[] = {
        "10", "6", "9", "3", "+", "-11", "*",
        "/", "*", "17", "+", "5", "+"
    };
    int size3 = sizeof(tokens3) / sizeof(tokens3[0]);
    printf("Output 3: %d\n", evalRPN(tokens3, size3));

    return 0;