#include <stdio.h>
#include "../utils/linked_list.h"

// 若相交，则切换头结点后的总路程相等，展开全段路程双指针会同时指向相交节点
// x+y+z+y = z+y+x+y
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *l1, *l2;
	l1 = headA, l2 = headB;

	// 若不想交则 NULL == NULL 会退出循环并返回
	while (l1 != l2) {
		if (l1 != NULL)
			l1 = l1->next;
		else
			l1 = headB;

		if (l2 != NULL)
			l2 = l2->next;
		else
			l2 = headA;
	}

	return l1;
}

int main() {
	int nums1[] = {1, 1};
	int nums2[] = {2};
	int nums3[] = {3, 4, 5, 6};
	struct ListNode *l1 = genList(nums1, 2);
	struct ListNode *l2 = genList(nums2, 1);
	struct ListNode *l3 = genList(nums3, 4);
	l1->next->next = l3;
	l2->next = l3;
	prList(getIntersectionNode(l1, l2)); // 3->4->5->6->NULL
}