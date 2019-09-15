//
// stack
//
struct Stack {
	int idx;
	unsigned cap;
	int *arr;
};

struct Stack *newStack(unsigned cap);

int isEmpty(struct Stack *s);

int isFull(struct Stack *s);

void push(struct Stack *s, int v);

int pop(struct Stack *s);

int peek(struct Stack *s);