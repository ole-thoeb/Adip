#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct StackNodeImpl{
	StackNode next;
	TYPE value;
};

struct StackImpl{
	StackNode nodes;
	int size;
};

Stack Stack_new(){
	Stack s = malloc(sizeof(struct StackImpl));
	s->size = 0;
	s->nodes = NULL;
	return s;
}

StackNode newNode(TYPE value){
	StackNode s = malloc(sizeof(struct StackNodeImpl));
	s->value = value;
	s->next = NULL;
	return s;
}

void deleteStack(StackNode node){
	free(node);
}

void Stack_push(Stack stack, TYPE value){
	StackNode new = newNode(value);
	new->next = stack->nodes;
	stack->nodes = new;
	stack->size++;
}

void Stack_delete(Stack stack){
	StackNode cur = stack->nodes;
	StackNode next = cur;
	while(cur != NULL){
		next = cur->next;
		deleteStack(cur);
		cur = next;
	}
	free(stack);
}

TYPE Stack_pop(Stack stack){
	StackNode temp = stack->nodes;
	TYPE v = temp->value;
	stack->nodes = temp->next;
	stack->size--;
	deleteStack(temp);
	return v;
}

TYPE Stack_peek(Stack stack){
	return stack->nodes->value;
}

int Stack_isEmpty(Stack stack){
	return stack->size == 0;
}

void Stack_print(Stack stack){
	StackNode cur = stack->nodes;
	while(cur != NULL){
		printf("%i, ", cur->value);
		cur = cur->next;
	}
	putchar('\n');
}