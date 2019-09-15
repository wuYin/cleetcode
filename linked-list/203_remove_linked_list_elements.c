#include <stdio.h>
#include <stdlib.h>
#include "../utils/linked_list.h"


// 注意头结点可能会丢失
struct ListNode *removeElements(struct ListNode *head, int val) {
	struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
	dummy->next = head;

	struct ListNode *prev, *cur;
	prev = dummy, cur = head;

	while (cur != NULL) {
		if (cur->val == val)
			prev->next = cur->next; // 删除 cur
		else
			prev = prev->next;

		cur = cur->next;
	}

	return dummy->next;
}


int main() {
	int nums1[] = {1, 1, 2, 3};
	struct ListNode *l1 = genList(nums1, 4);
	prList(removeElements(l1, 1)); // 2->3->NULL
}