#include <stdio.h>


// 换个角度
// 只要不是 0 就放到数组头部
void moveZeroes(int *nums, int numsSize) {
	int j = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != 0)
			nums[j++] = nums[i];
	}

	for (int i = j; i < numsSize; i++) {
		nums[i] = 0;
	}
}


int main() {
	int nums[] = {0, 1, 0, 3, 12};
	moveZeroes(nums, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", nums[i]);
	}
}