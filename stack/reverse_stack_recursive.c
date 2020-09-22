#include "stack.h"

#define SIZE 10

void insert_at_bottom(stack *s, int x) {
	stack temp;
	init(&temp, SIZE);

	while(s->top != 0) {
		push(&temp, top(s));
		pop(s);
	}

	push(s, x);

	while(temp.top != 0) {
		push(s, top(&temp));
		pop(&temp);
	}
}

void reverse(stack *s) {
	int t = top(s);
	pop(s);

	if (s->top != 0) {
		reverse(s);
	}
	
	insert_at_bottom(s, t);
}

int main() {
	stack a;
	init(&a, SIZE);

	for (int i = 0; i < SIZE-1; i++)
		push(&a, i + 1);
	
	reverse(&a);

	while (a.top != 0) {
		printf("%d ", top(&a));
		pop(&a);
	}

	return 0;
}