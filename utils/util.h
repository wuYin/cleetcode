struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *genList(int *nums, int numsSize);

void prList(struct ListNode *head);