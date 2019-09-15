#include <stdio.h>
#include <stdlib.h>
#include "../utils/stack.h"

typedef struct {
	struct Stack *mins;
	struct Stack *nums;
} MinStack;

MinStack *minStackCreate() {
	MinStack *s = (MinStack *) malloc(sizeof(MinStack));
	s->mins = newStack(1000);
	s->nums = newStack(1000);
	return s;
}

void minStackPush(MinStack *s, int x) {
	push(s->nums, x);
	if (isEmpty(s->mins) || x <= peek(s->mins)) // <= 即使是相同的最小值也要入栈，避免 case: 0 1 0
		push(s->mins, x);
}

void minStackPop(MinStack *s) {
	if (pop(s->nums) == peek(s->mins))
		pop(s->mins);
}

int minStackTop(MinStack *s) {
	return peek(s->nums);
}

int minStackGetMin(MinStack *s) {
	return peek(s->mins);
}

void minStackFree(MinStack *s) {
	free(s);
}


int main() {
	MinStack *s = minStackCreate();
	minStackPush(s, 0);
	minStackPush(s, 1);
	minStackPush(s, 0);
	printf("%d\n", minStackGetMin(s)); // 0
	minStackPop(s);
	printf("%d\n", minStackGetMin(s)); // 0
}