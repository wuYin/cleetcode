//
// linked list
//
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *genList(int *nums, int numsSize);

void prList(struct ListNode *head);

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