# Creating an empty stack, via array
stack = []

# Pushing elements onto the stack
stack.append(1)
stack.append(2)
stack.append(3)
print(stack)

top_element = stack.pop()  # Removes and returns 3
print(top_element)
print(stack)
# Peeking at the top element
peek_element = stack[-1]  # Returns 2 without removing it
print(stack)
print(peek_element)