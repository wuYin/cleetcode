#include <stdio.h>
#include "../utils/linked_list.h"

// 快慢双指针
struct ListNode *middleNode(struct ListNode *head) {
	struct ListNode *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


int main() {
	int nums1[] = {1, 2, 3, 4, 5};
	struct ListNode *l1 = genList(nums1, 5);
	prList(middleNode(l1)); // 3->4->5->NULL
}