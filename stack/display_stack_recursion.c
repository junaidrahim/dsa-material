#include "stack.h"

void display(stack* s){
	int t = top(s);
	pop(s);

	if(s->top != 0) {
		display(s);
	}

	printf("%d ", t);
	push(s, t);
}

int main(){
	stack s;
	init(&s, 10);
	
	for(int i=0; i<10; i++){
		push(&s, i);
	}
	
	display(&s);

	return 0;
}