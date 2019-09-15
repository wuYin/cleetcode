#include <stdio.h>

// 曹冲称象的脑经急转弯
int missingNumber(int *nums, int numsSize) {
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	int fullSum = (numsSize + 1) * numsSize / 2;
	return fullSum - sum;
}


int main() {
	int nums[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
	printf("%d\n", missingNumber(nums, 9));
}