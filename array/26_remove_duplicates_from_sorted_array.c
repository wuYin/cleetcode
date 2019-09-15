#include <stdio.h>


// 双指针将不重复的值堆积到数组前边即可
int removeDuplicates(int *nums, int numsSize) {
	if (numsSize <= 1)
		return numsSize;

	int l = 1;
	for (int r = 1; r < numsSize; r++)
		if (nums[r] != nums[r - 1])
			nums[l++] = nums[r];

	return l;
}


int main() {
	int nums[] = {1, 1, 2};
	printf("%d\n", removeDuplicates(nums, 3));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", nums[i]);
	}
}

