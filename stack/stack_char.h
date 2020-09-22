#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct STACK_S {
	int size;
	char *arr;
	int top;
} stack_char;

void init(stack_char *s, int size);
void push(stack_char *s, char x);
void pop(stack_char *s);
char top(stack_char *s);

void init(stack_char *s, int size) {
	s->size = size;
	s->arr = (char *)malloc(sizeof(char) * size);
	s->top = 0;
}

void push(stack_char *s, char x) {
	if (s->top == s->size) puts("Stack Overflow");
	else {
		s->arr[s->top] = x;
		++(s->top);
	}
}

void pop(stack_char *s) {
	if (s->top == 0) puts("Stack Underflow");
	else {
		s->arr[s->top - 1] = 0;
		--(s->top);
	}
}

char top(stack_char *s) { return *(s->arr + s->top - 1); }

#endif