#include <stdlib.h>

typedef struct tagArrayStack
{
	int		Capacity;
	int		Top;
	Node	*Nodes;
}	ArrayStack;

void	AS_Push(ArrayStack *Stack, ElementType Data)
{
	int	Position = Stack->Top;

	if (Position <= Capacity)
	{
		Stack->Nodes[Position].Data = Data;
		Stack->Top++;
	}
	else
	{
		Stack = realloc(sizeof(ArrayStack) * (Capacity * 30 / 100));
		Stack->Nodes[Position].Data = Data;
		Stack->Top++;
	}
}

void	AS_Pop(ArrayStack *Stack)
{
	int	Position = --(Stack->Top);
	int	_Cap = Stack->Capacity * 70 / 100;

	if (Position < _Cap)
		Stack = realloc(sizeof(Stack) * _Cap);
	return (Stack->Nodes[Position].Data);
}
