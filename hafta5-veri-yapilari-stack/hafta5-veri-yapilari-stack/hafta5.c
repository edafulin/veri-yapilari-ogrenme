#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct stack {
	int top;
	unsigned capacity;
	int* array;
};
struct stack* createStack(unsigned ck) {
	struct stack* yeni = (struct stack*)malloc(sizeof(struct stack));
	yeni->top = -1;
	yeni->capacity = ck;
	yeni->array = (int*)malloc(sizeof(int) * ck);
	return yeni;
}
int isEmpty(struct stack* sl) {
	return (sl->capacity - 1) == sl->top;
}
int isFull(struct stack* sl) {
	return (sl->capacity - 1) == sl->top;
}
void peek(struct stack* sl) {
	printf("zirvedeki deger = %d\n", sl->array[sl->top]);
}
void push(struct stack* sl, int item) {
	if (isFull(sl))
		return;
	sl->top = sl->top + 1;
	sl->array[sl->top] = item;
}
int pop(struct stack* sl) {//elemanlar silinmez sadece o alan belleðe geri  verilir
	if (isEmpty(sl))
		return INT_MIN;
	/*int item = sl->array[sl->top];
	sl->top = sl->top - 1;
	return item;*/
	return sl->array[sl->top--];
}

int main() {
	struct stack* s2 = createStack(15);
	push(s2, 5); 
	push(s2, 15); 
	push(s2, 25); 
	push(s2, 35);
	peek(s2);
	printf("alinan= %d\n", pop(s2));
	printf("....= %d\n", s2->array[s2->top]);
	printf("....= %d\n", s2->array[s2->top+1]);
	return 0;
}
