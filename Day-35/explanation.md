Implement a Queue using two stacks.

Approach:
- Use two stacks: stack1 (input) and stack2 (output).
- Push operation inserts into stack1.
- For pop/peek, move all elements from stack1 to stack2, access the front element, then move elements back.
- This ensures FIFO behavior using LIFO stacks.