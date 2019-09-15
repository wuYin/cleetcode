#include <stdio.h>

#define MAX(a, b) ((a) > (b)) ? (a): (b)

// 动态规划
// 状态转移方程：f(n) = max(f(n-1)+arr[n], arr[n])
int maxSubArray(int *nums, int numsSize) {
	int sum = nums[0], maxSum = sum;

	for (int i = 1; i < numsSize; i++) {
		sum = MAX(sum + nums[i], nums[i]);
		maxSum = MAX(maxSum, sum);
	}

	return maxSum;
}


int main() {
	int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	printf("%d\n", maxSubArray(nums, 9));
}