#include <stdio.h>
#include <limits.h>

// 遍历三次分别找出第 1 2 3 大的数，优化为遍历一次即可
int thirdMax(int *nums, int numsSize) {
	long a, b, c;
	a = b = c = LONG_MIN;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > a)
			c = b, b = a, a = nums[i]; // 发现更大数则顺延
		if (nums[i] < a && nums[i] > b)
			c = b, b = nums[i];
		if (nums[i] < b && nums[i] > c)
			c = nums[i];
	}

	// 不存在第三大则返回最大
	if (c == LONG_MIN)
		return a;
	return c;
}


int main() {
	int nums[] = {1, 2};
	printf("%d\n", thirdMax(nums, 2));
}