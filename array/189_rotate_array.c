#include <stdio.h>

// 每次都把最后一个数挪到第一位即可
void rotate(int *nums, int numsSize, int k) {
	while (k-- > 0) {
		int last = nums[numsSize - 1];
		for (int i = numsSize - 1; i > 0; i--)
			nums[i] = nums[i - 1];

		nums[0] = last;
	}
}


int main() {
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	rotate(nums, 7, 3);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", nums[i]);
	}
}