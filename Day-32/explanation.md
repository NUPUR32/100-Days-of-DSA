Design stack that supports getMin in O(1):

1. Use two stacks: main stack and min stack
2. Min stack keeps track of minimum at each level
3. On push: update min stack
4. On pop: pop from both stacks
5. getMin: return top of min stack

Key Points:
- Parallel stacks approach
- Min stack mirrors main stack
- All operations in O(1)