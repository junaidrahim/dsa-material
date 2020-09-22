#include "stack.h"

void copy(stack *a, stack *b){
	stack temp;
	init(&temp, 10);

	while(a->top != 0) {
		int t = top(a);
		push(&temp, t);
		pop(a);
	}

	while(temp.top != 0) {
		int t = top(&temp);
		push(b, t);
		pop(&temp);
	}
}


int main(){
	stack a;
	stack b;

	init(&a, 10);
	init(&b, 10);

	for(int i=0; i<9; i++)
		push(&a, i+1);

	copy(&a, &b);

	while(b.top != 0){
		printf("%d ", top(&b));
		pop(&b);
	}

	return 0;
}