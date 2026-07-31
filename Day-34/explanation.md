Evaluate a mathematical expression containing +, -, *, / using a stack.

Approach:
- Use a stack to handle operator precedence.
- + : push number
- - : push negative number
- * and / : compute immediately using stack top
- Final result is the sum of stack elements.