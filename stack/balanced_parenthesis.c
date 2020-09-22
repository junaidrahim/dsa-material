#include "stack_char.h"
#include <string.h>

int bracket_type(char c) { // 1 for open, -1 for close, 0 for invalid
	if (c == '(' || c == '{' || c == '[') return 1;
	else if (c == ')' || c == '}' || c == ']')
		return -1;
	else
		return 0;
}

int main() {
	char b[100];

	printf("Enter the expression: ");
	scanf("%s", b);

	stack_char s;
	init(&s, 100);

	int len = strlen(b);

	for (int i = 0; i < len; i++) {
		if(bracket_type(b[i]) == 1) push(&s, b[i]);
		else if (bracket_type(b[i]) == -1) {
			if(b[i] == ')' && top(&s) == '(') pop(&s);
			else if(b[i] == ']' && top(&s) == '[') pop(&s);
			else if(b[i] == '}' && top(&s) == '{') pop(&s);
		}
		else push(&s, b[i]);
	}

	if(s.top == 0)
		puts("Balanced");
	else 
		puts("Unbalanced");

	return 0;
}