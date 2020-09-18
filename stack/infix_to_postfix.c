#include "stack.h"

#include <string.h>
#include <stdbool.h>


int precedence(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else
		return -1;
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

int main()
{
	char *infix = "a+(b-c)*d/e";

	stack s;
	init(&s, strlen(infix) + 5);

	char postfix[strlen(infix) + 1];
	int index = 0;

	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (isOperator(infix[i]))
		{
			while ((s.top != 0) && (precedence(top(&s)) >= precedence(infix[i])))
			{
				postfix[index] = top(&s);
				pop(&s);
				index++;
			}

			push(&s, infix[i]);
		}
		else if (infix[i] == '(')
		{
			push(&s, '(');
		}
		else if (infix[i] == ')')
		{
			while ((s.top != 0) && (top(&s) != '('))
			{
				postfix[index] = top(&s);
				pop(&s);
				index++;
			}

			if (top(&s) == '(')
				pop(&s);
		}
		else
		{
			postfix[index] = infix[i];
			index++;
		}
	}

	while (s.top != 0)
	{
		postfix[index] = top(&s);
		pop(&s);
		index++;
	}

	postfix[index] = '\0';

	printf("%s\n", postfix);

	return 0;
}