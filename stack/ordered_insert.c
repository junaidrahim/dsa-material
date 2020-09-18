#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void ordered_insert(stack *s)
{
	int a[] = {9,6,7,3,1,8,4,8,7,5};
	for (int i = 0; i <10; i++){
		stack temp;
		init(&temp, 10);

		if(s->top == 0) {
			push(s, a[i]);
			continue;
		}

		while(top(s) <= a[i] && s->top!=0) {
			push(&temp, top(s));
			pop(s);
		}

		push(s, a[i]);

		while(temp.top != 0){
			push(s, top(&temp));
			pop(&temp);
		}
	}
}

int main()
{
	stack s;
	init(&s, 11);
	ordered_insert(&s);

	while(s.top != 0){
		printf("%d ", top(&s));
		pop(&s);
	}

	return 0;
}