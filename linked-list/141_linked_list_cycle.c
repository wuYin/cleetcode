#include <stdio.h>
#include <stdbool.h>
#include "../utils/util.h"


// 快指针必定会遇到慢指针
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;

	struct ListNode *slow, *fast;
	slow = fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}

	return false;
}

int main() {
	int nums[] = {1, 1, 2};
	struct ListNode *l = genList(nums, 3);
	prList(l);
	l->next->next->next = l->next;
	printf("%d\n", hasCycle(l));
}