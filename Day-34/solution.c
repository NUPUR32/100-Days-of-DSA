#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[1000];
    int top = -1;
    char op = '+';
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op = s[i];
            i++;
        }
        else {
            int num = 0;

            while (s[i] != '\0' && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] *= num;
            }
            else if (op == '/') {
                stack[top] /= num;   // Truncates toward zero
            }
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}

int main() {
    char s1[] = "3+2*2";
    char s2[] = " 3/2 ";
    char s3[] = " 3+5 / 2 ";
    char s4[] = "14-3/2";

    printf("Expression: %s\nResult: %d\n\n", s1, calculate(s1));
    printf("Expression: %s\nResult: %d\n\n", s2, calculate(s2));
    printf("Expression: %s\nResult: %d\n\n", s3, calculate(s3));
    printf("Expression: %s\nResult: %d\n\n", s4, calculate(s4));

    return 0;
}