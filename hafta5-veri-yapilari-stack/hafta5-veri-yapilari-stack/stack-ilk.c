#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};
struct stack* createStack(unsigned capacity) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
struct stack* isFull(struct Stack* stack) {
	return stack->top == stack->capacity - 1;
}

struct stack* isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

void peek (struct Stack* stack) {
	if(isEmpty(stack)) {
		return;
	}
	return stack->array[stack->top];
}


void push(struct Stack* x,int item) {
	if(isFull(x)) {
		return;
	}
	x->top = x->top + 1;
	x->array[x->top] = item;
}


int pop(struct Stack* x) {
	if(isEmpty(x)) {
		return;
	}
	return x->array[x->top-1];
}


int main () {
	struct Stack* s2 = createStack(100);
	push(s2, 10);
	push(s2, 20);
	push(s2, 30);
	printf("%d", pop(s2));
	push(s2, 30);
	return 0;
}