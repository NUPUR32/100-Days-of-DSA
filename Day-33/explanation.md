Evaluate postfix expression:

1. Scan tokens left to right
2. If number: push to stack
3. If operator: pop two operands, compute, push result
4. Final result is top of stack

Key Points:
- Postfix has no parentheses
- No precedence needed
- Direct evaluation possible