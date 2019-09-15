#include <stdio.h>
#include "../utils/util.h"

// 依次拼接即可
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	// 参数检查
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode *p1 = l1, *p2 = l2;
	struct ListNode *head = NULL;
	struct ListNode **cur = &head; // 指向新头结点指针的指针，head 仅是指向头结点内存区域的指针

	while (1) {
		if (p1 && p2) {
			if (p1->val < p2->val) {
				*cur = p1;
				p1 = p1->next;
			} else {
				*cur = p2;
				p2 = p2->next;
			}
		} else if (p1 && p2 == NULL) {
			*cur = p1;
			p1 = p1->next;
		} else if (p2 && p1 == NULL) {
			*cur = p2;
			p2 = p2->next;
		} else {
			break;
		}
		cur = &((*cur)->next); // cur 只有指向 ListNode 指针，才能修改其 next 指针域的值
	}
	return head;
}


int main() {
	int nums1[] = {1, 2, 4};
	int nums2[] = {1, 3, 4};
	struct ListNode *l1 = genList(nums1, 3);
	struct ListNode *l2 = genList(nums2, 3);
	prList(mergeTwoLists(l1, l2));
}