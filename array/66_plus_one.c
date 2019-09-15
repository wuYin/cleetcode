#include <stdio.h>
#include <stdlib.h>


int *plusOne(int *digits, int digitsSize, int *returnSize) {
	int *res = (int *) malloc((digitsSize + 1) * sizeof(int)); // 多分配一位
	int plus = 1;
	for (int i = digitsSize - 1; i >= 0; i--) { // 从个位开始相加
		plus += digits[i];
		res[i + 1] = plus % 10; // 和取余后从后边的个位开始存
		plus /= 10;
	}

	*returnSize = digitsSize;
	if (plus == 1) { // 最后有进位
		res[0] = 1;
		(*returnSize)++;
		return res;
	} else {
		return res + 1; // 无进位则忽略数组第一个元素
	}
}


int main() {
	int nums[] = {4, 3, 2, 1};
	int size;
	int *newNums = plusOne(nums, 4, &size);
	for (int i = 0; i < 4; i++) {
		printf("%d ", newNums[i]);
	}
}