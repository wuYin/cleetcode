#include <stdio.h>

// 思路
// 向后遍历，取最小值，并计算最大差值
int maxProfit(int *prices, int pricesSize) {
	if (pricesSize == 0)
		return 0;

	int min = prices[0];
	int maxProfit = 0;
	for (int i = 1; i < pricesSize; i++) {
		if (prices[i] < min)
			min = prices[i];
		if (prices[i] - min > maxProfit)
			maxProfit = prices[i] - min;
	}

	return maxProfit;
}


int main() {
	int prices[] = {7, 1, 5, 3, 6, 4};
	printf("%d\n", maxProfit(prices, 6));
}