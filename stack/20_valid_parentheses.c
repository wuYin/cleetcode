#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../utils/util.h"

// 开符号进栈，遇闭符号则出栈匹配
bool isValid(char *s) {
	int len = strlen(s);
	struct Stack *stack = newStack(len);
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(stack, s[i]);
		} else {
			char c2 = pop(stack);
			if ((s[i] == ')' && c2 != '(') ||
				(s[i] == ']' && c2 != '[') ||
				(s[i] == '}' && c2 != '{'))
				return false;
		}
	}

	if (isEmpty(stack))
		return true; // 空字符串或完全匹配均有效
	return false;
}


int main() {
	printf("%d\n", isValid("([])")); // 1
}