#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct ListNode *genList(int *nums, int numsSize) {
	struct ListNode *head = (struct ListNode *) calloc(numsSize, sizeof(struct ListNode));
	struct ListNode **p = &head;
	for (int i = 0; i < numsSize; i++) {
		(*p)->val = nums[i];
		(*p)->next = *p + 1;
		p = &((*p)->next);
	}
	*p = NULL;
	return head;
}

void prList(struct ListNode *head) {
	while (head != NULL) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}
