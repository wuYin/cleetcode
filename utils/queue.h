//
// queue
//
struct Queue {
	int head, rear;
	int size;
	unsigned cap;
	int *arr;
};

struct Queue *newQueue(unsigned cap);

int isFull(struct Queue *q);

int isEmpty(struct Queue *q);

void enQueue(struct Queue *q, int v);

int deQueue(struct Queue *q);

int front(struct Queue *q);

int rear(struct Queue *q);

int size(struct Queue *q);