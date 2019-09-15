#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "queue.h"

// 用前后指针区间在数组上模拟队列
struct Queue *newQueue(unsigned cap) {
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	q->cap = cap;
	q->size = 0;
	q->head = 0;
	q->rear = cap - 1;
	q->arr = (int *) malloc(cap * sizeof(int));
	return q;
}

int isFull(struct Queue *q) {
	return q->size == q->cap;
}

int isEmpty(struct Queue *q) {
	return q->size == 0;
}

void enQueue(struct Queue *q, int v) {
	if (isFull(q))
		return;
	q->rear = (q->rear + 1) % q->cap; // 回收头部区间
	q->arr[q->rear] = v;
	q->size++;
}

int deQueue(struct Queue *q) {
	if (isEmpty(q))
		return INT_MIN;

	int v = q->arr[q->head];
	q->head = (q->head + 1) % q->cap;
	q->size--;
	return v;
}

int front(struct Queue *q) {
	if (isEmpty(q))
		return INT_MIN;
	return q->arr[q->head];
}

int rear(struct Queue *q) {
	if (isEmpty(q))
		return INT_MIN;
	return q->arr[q->rear];
}

int size(struct Queue *q) {
	return q->size;
}