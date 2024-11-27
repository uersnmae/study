#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct StackType {
	char arr[100];	// int형 데이터 100
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

void push(StackType *s, char value)
{
	if (is_full(s))
		exit(1);
	s->arr[++(s->top)] = value;
}

char pop(StackType *s)
{
	if (is_empty(s))
		exit(1);
	return (s->arr[(s->top)--]);
}

char peek(StackType *s)
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

void	infix_to_postfix(char exp[])
{
	char	ch;
	char	top_op;
	int		len = strlen(exp);
	StackType s;

	init(&s);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		switch(ch)
		{
			case '+': case'-': case '*': case '/':
			{
				while (!is_empty(&s) && prec(ch) <= prec(peek(&s))) 
					printf("%c", pop(&s));
				push (&s, ch);
				break ;
			}
			case '(':
			{
				push(&s, ch);
				break ;
			}
			case ')':
			{
				top_op = pop(&s);
				while (top_op != '(')
				{
					printf("%c", top_op);
					top_op = pop(&s);
				}
				break;
			}
			default:
			{
				printf("%c", ch);
				break;
			}
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main()
{
	char *s = "(2+3)*4+9";
	
	printf("%s\n", s);
	infix_to_postfix(s);
	printf("\n");
	return(0);
}
