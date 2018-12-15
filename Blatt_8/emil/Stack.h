#pragma once

typedef int TYPE;
typedef struct StackImpl *Stack;
typedef struct StackNodeImpl *StackNode;

Stack Stack_new();
StackNode newNode(TYPE value);
void Stack_push(Stack stack, TYPE value);
void Stack_delete(Stack stack);
TYPE Stack_pop(Stack stack);
TYPE Stack_peek(Stack stack);
int Stack_isEmpty(Stack stack);
void Stack_print(Stack stack);