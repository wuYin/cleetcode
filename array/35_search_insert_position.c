#include <stdio.h>

// 二分查找结束时 l / r-1 的位置即应插入的位置
int searchInsert(int *nums, int numsSize, int target) {
	int l = 0, r = numsSize - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (target < nums[mid])
			r = mid - 1;
		else if (target > nums[mid])
			l = mid + 1;
		else
			return mid;
	}

	return l;
}


int main() {
	int nums[] = {1, 3, 5, 6};
	printf("%d\n", searchInsert(nums, 4, 5));
}