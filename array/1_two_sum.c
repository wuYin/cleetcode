#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 数组元素
struct elem {
	int k;
	int v;
};

// qsort 需实现的比较函数
static int less(const void *a, const void *b) {
	return ((struct elem *) a)->v > ((struct elem *) b)->v;
}

// 思路：将数组排序，前后双指针遍历
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	// 分配辅助数组内存，初始化并排序
	struct elem *vs = malloc(numsSize * sizeof(struct elem *));
	for (int i = 0; i < numsSize; ++i) {
		vs[i].k = i;
		vs[i].v = nums[i];
	}
	qsort(vs, numsSize, sizeof(struct elem *), less);

	// 双指针遍历
	int *res = malloc(2 * sizeof(int));
	int l = 0, r = numsSize - 1;;
	while (l < r) {
		if (vs[l].v + vs[r].v < target) { // 值小则左指针右移，注意去重
			while (++l < r && vs[l].v == vs[l - 1].v); // 注意 ++l 在条件表达式求值时至少执行一次
		} else if (vs[l].v + vs[r].v > target) { // 值大则右指针左移，去重
			while (--r > l && vs[r].v == vs[r + 1].v);
		} else {
			res[0] = vs[l].k;
			res[1] = vs[r].k;
			*returnSize = 2;
			return res;
		}
	}
	*returnSize = 0;
	return NULL;
}



// 线性查找 O(1) 的哈希表性能最好，用数组模拟 map
// {2, 7 11, 15}  9
// {0:-1, 1:-1, 2:-1, 3:-1, 4:-1, 5:-1} // 数组长为 (9-2)-2+1=6
// {2:-1, 3:-1, 4:-1, 5:-1, 6:-1, 7:-1} // 为避免 [0,min] 区间的内存浪费，将 [min, max] 映射到 [0, max-min] 上
#define MIN(a, b) ((a) > (b)) ? (b) : (a)

int *twoSum2(int *nums, int numsSize, int target, int *returnSize) {
	*returnSize = 2;

	// 取区间范围初始化哈希表
	int min = INT_MAX;
	for (int i = 0; i < numsSize; ++i) {
		min = MIN(min, nums[i]);
	}
	int mapSize = (target - min) - min + 1; // 可能取值范围的哈希表

	int *map = (int *) malloc(mapSize * sizeof(int));
	for (int i = 0; i < mapSize; i++) {
		map[i] = -1; // 初始化
	}

	int *res = (int *) malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] - min > mapSize - 1) // 越界不存在
			continue;

		if (map[target - nums[i] - min] == -1) {
			map[nums[i] - min] = i;
		} else {
			res[0] = map[target - nums[i] - min];
			res[1] = i;
			return res;
		}
	}

	return NULL;
}

int main() {
	int nums[] = {2, 7, 11, 15};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize;
	//int *idx = twoSum(nums, numsSize, target, &returnSize);
	int *idx = twoSum2(nums, numsSize, target, &returnSize);
	for (int i = 0; i < 2; ++i) {
		printf("%d ", idx[i]);
	}
}