#include <stdio.h>
#include <stdlib.h>

// 双指针遍历就完事了
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
	*returnSize = 2;
	int *res = (int *) malloc(2 * sizeof(int));
	int l = 0, r = numbersSize - 1;
	int sum;
	while (l <= r) {
		sum = numbers[l] + numbers[r];
		if (sum < target)
			l++;
		else if (sum > target)
			r--;
		else {
			res[0] = l + 1;
			res[1] = r + 1;
			return res;
		}
	}

	return NULL;
}


int main() {
	int nums[] = {2, 7, 11, 15};
	int returnSize;
	int *res = twoSum(nums, 4, 9, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d\n", res[i]);
	}
}