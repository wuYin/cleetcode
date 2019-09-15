#include <stdio.h>
#include <stdlib.h>

// 思路
// 杨辉三角规律 a[i][j] = a[i-1][j] + a[i-1][j-1]
// 注意二维数组的内存分配
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
	int **res = (int **) calloc(numRows, sizeof(int *));
	*returnSize = numRows;                                     // 记录行数
	*returnColumnSizes = (int *) calloc(numRows, sizeof(int)); // 记录各行有效长度

	for (int i = 0; i < numRows; i++) {
		(*returnColumnSizes)[i] = i + 1;
		res[i] = (int *) calloc(i + 1, sizeof(int));
		res[i][0] = 1; // 最左侧元素
		for (int j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j] + res[i - 1][j - 1]; // 填充中间元素
		}
		res[i][i] = 1; // 最右侧元素
	}

	return res;
}


int main() {
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int **res = generate(4, &returnSize, &returnColumnSizes);

	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}