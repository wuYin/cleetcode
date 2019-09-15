#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"

struct Stack *newStack(unsigned cap) {
	struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
	s->cap = cap;
	s->idx = -1; // 有效索引初始化为 -1，自增后从 0 开始索引
	s->arr = (int *) malloc(cap * sizeof(int));
	return s;
}

int isEmpty(struct Stack *s) {
	return s->idx == -1;
}

int isFull(struct Stack *s) {
	return s->idx == s->cap - 1;
}

void push(struct Stack *s, int v) {
	if (isFull(s))
		return;
	s->arr[++s->idx] = v;
}

int pop(struct Stack *s) {
	if (isEmpty(s))
		return INT_MIN;
	return s->arr[s->idx--];
}

int peek(struct Stack *s) {
	if (isEmpty(s))
		return INT_MIN;
	return s->arr[s->idx];
}