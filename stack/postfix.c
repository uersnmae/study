#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct StackType {
	int arr[100];	// int형 데이터 100
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;	// 배열은 index 0부터 시작
}

// empty : return 1
// !empty : return 0
int is_empty(StackType *s)
{
	if (s->top == -1)
		return (1);
	return (0);
}

// full : return 1
// !full : return 0
int is_full(StackType *s)
{
	if (s->top == SIZE - 1)
		return (1);
	return (0);
}

void push(StackType *s, int value)
{
	if (is_full(s))
		exit(1);
	s->arr[++(s->top)] = value;
}

int pop(StackType *s)
{
	if (is_empty(s))
		exit(1);
	return (s->arr[(s->top)--]);
}

int peek(StackType *s)
{
	if (is_empty(s))
		exit(1);
	return (s->arr[(s->top)]);
}

int	prec(char op)
{
	switch(op)
	{
		case '(': case ')':
			return (0);
		case '+': case '-':
			return (1);
		case '*': case '/':
			return (2);
	}
	return (-1);
}

int	eval(char exp[])
{
	int op1, op2, value;
	char ch;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';
			push(&s, value);
		}
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch(ch)
			{
				case '+':
				{
					push(&s, op1 + op2);
					break ;
				}
				case '-':
				{
					push(&s, op1 - op2);
					break ;
				}
				case '*':
				{
					push(&s, op1 * op2);
					break ;
				}
				case '/':
				{
					push(&s, op1 / op2);
					break ;
				}
			}
		}
	}
	return (pop(&s));
}

int	main(void)
{
	int result;
	result = eval("82/3-32*+");
	printf("--> %d", result);
}
