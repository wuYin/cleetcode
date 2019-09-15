#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/util.h"

typedef struct {
	struct Stack *s1; // 从 s1 入栈
	struct Stack *s2; // 从 s2 出栈，摊还复杂度为 O(1)
} MyQueue;


MyQueue *myQueueCreate() {
	MyQueue *q = (MyQueue *) malloc(sizeof(MyQueue));
	q->s1 = newStack(1000);
	q->s2 = newStack(1000);
	return q;
}

void myQueuePush(MyQueue *q, int x) {
	push(q->s1, x);
}

int myQueuePop(MyQueue *q) {
	if (isEmpty(q->s2)) {
		while (!isEmpty(q->s1))
			push(q->s2, pop(q->s1));
	}

	return pop(q->s2);
}

int myQueuePeek(MyQueue *q) {
	if (isEmpty(q->s2)) {
		while (!isEmpty(q->s1))
			push(q->s2, pop(q->s1));
	}

	return peek(q->s2);
}

bool myQueueEmpty(MyQueue *q) {
	return isEmpty(q->s1) && isEmpty(q->s2) ? true : false;
}

void myQueueFree(MyQueue *q) {
	free(q);
}

int main() {
	MyQueue *q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	printf("%d\n", myQueuePeek(q));  // 1
	printf("%d\n", myQueuePop(q));   // 1
	printf("%d\n", myQueueEmpty(q)); // 0
}
