#include <stdio.h>
#include "../utils/util.h"

// 画图一目了然
struct ListNode *reverseList(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	// p1 不是从 head 出发，而是从头节点的前驱出发
	// 否则 head 的后驱连接不断开，head.Next -> head -> head.Next 形成循环链表
	struct ListNode *p1, *p2, *p3;
	p1 = NULL;
	p2 = head;
	p3 = head->next;

	while (p2 != NULL) {
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
			p3 = p3->next; // 注意判断 p3 最先到链表尾部为 nil
	}

	// 循环退出时 p2=p3=nil，返回 p1
	return p1;
}


int main() {
	int nums1[] = {1, 2, 3};
	struct ListNode *l1 = genList(nums1, 3);
	prList(reverseList(l1)); // 3->2->1->NULL
}