#include <stdio.h>

// 思路
// 对两个数组分别从后向前遍历，不断将最大值由后到前放入 nums1 中，最终 nums1 合并后仍有序
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[k] = nums1[i];
			i--;
		} else {
			nums1[k] = nums2[j];
			j--;
		}
		k--;
	}

	// 只有 j 可能会剩余
	while (j >= 0)
		nums1[k--] = nums2[j--];
}


int main() {
	int nums1[] = {1, 2, 3, 0, 0, 0};
	int nums2[] = {2, 5, 6};
	merge(nums1, 6, 3, nums2, 3, 3);
	for (int i = 0; i < 6; i++) {
		printf("%d\n", nums1[i]);
	}
}