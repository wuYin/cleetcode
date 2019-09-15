#include <stdio.h>
#include "../utils/linked_list.h"

// 从第二个节点开始遍历，若重复则删除
struct ListNode *deleteDuplicates(struct ListNode *head) {
	if (head == NULL)
		return NULL;

	// head 不会丢失
	struct ListNode *pre = head;
	struct ListNode *cur = head->next;

	while (cur != NULL) {
		if (pre->val == cur->val)
			pre->next = cur->next; // 重复则删除 cur
		else
			pre = cur;

		cur = cur->next;
	}

	return head;
}


int main() {
	int nums1[] = {1, 1, 2};
	struct ListNode *l1 = genList(nums1, 3);
	prList(deleteDuplicates(l1));
}