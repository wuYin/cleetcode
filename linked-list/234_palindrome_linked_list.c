#include <stdio.h>
#include <stdbool.h>
#include "../utils/util.h"

// 暴力判回文
bool isPalindrome(struct ListNode *head) {
	// 快慢指针取链表中点
	struct ListNode *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// 反转后半部分
	struct ListNode *prev = NULL, *next = NULL;
	while (slow) {
		next = slow->next; // 调换 slow 节点的前后指针
		slow->next = prev;
		prev = slow;
		slow = next;
	}
	struct ListNode *newHead = prev;

	// 逐一比较
	while (head && newHead) {
		if (head->val != newHead->val)
			return false;
		head = head->next;
		newHead = newHead->next;
	}
	return true;
}


int main() {
	int nums1[] = {1, 2, 3, 2, 1};
	struct ListNode *l1 = genList(nums1, 5);
	printf("%d\n", isPalindrome(l1)); // 1
}