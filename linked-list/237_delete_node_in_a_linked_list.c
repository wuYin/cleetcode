#include <stdio.h>
#include "../utils/linked_list.h"

void deleteNode(struct ListNode *node) {
	if (node == NULL || node->next == NULL) // node 已知非尾结点
		return;

	// 巧妙地通过复制下一节点的值实现自删除
	node->val = node->next->val;
	node->next = node->next->next;
}

int main() {
	int nums1[] = {1, 2, 3, 4, 5};
	struct ListNode *l1 = genList(nums1, 5);
	deleteNode(l1->next->next);
	prList(l1); // 1->2->4->5->NULL
}