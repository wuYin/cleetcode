#include <stdio.h>

// 值不等则放到前边
int removeElement(int *nums, int numsSize, int val) {
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != val)
			nums[count++] = nums[i];
	}
	return count;
}


int main() {
	int nums[] = {3, 2, 2, 3};
	removeElement(nums, 4, 3);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", nums[i]);
	}
}