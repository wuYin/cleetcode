#include <stdio.h>

// 思路
// 假设第一个元素就是 majority，向后遍历遇到相同的数，计数器加一，否则减一换数
// majority 的数一定存在，总能抵消其他数字
int majorityElement(int *nums, int numsSize) {
	int majority = nums[0];
	int mc = 1;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == majority)
			mc++;
		else
			mc--;

		if (mc == 0) {
			majority = nums[i];
			mc = 1;
		}
	}

	return majority;
}


int main() {
	int nums[] = {2, 2, 1, 1, 1, 2, 2};
	printf("%d\n", majorityElement(nums, 7));
}