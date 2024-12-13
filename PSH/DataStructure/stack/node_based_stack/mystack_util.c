#include "mystack.h"

void	ft_createstack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

void	ft_destroystack(t_stack *stack)
{
	while (!ft_isempty(stack))
	{
		t_node *popped = ft_pop(stack);
		ft_destroynode(popped);
	}
	free(stack);
}

t_node	*ft_createnode(char *newdata)
{
	t_node	*newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = (char *)malloc(strlen(newdata) + 1);

	strcpy(newnode->data, newdata);
	return (newnode);
}

void	ft_destroynode(t_node *node)
{
	free(node->data);
	free(node);
}

void	ft_push(t_stack *stack, t_node *newnode)
{
	if (stack->list == NULL)
		stack->list = newnode;
	else
		stack->top->next = newnode;
	stack->top = newnode;
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*topnode = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		t_node	*currenttop = stack->list;
		while (currenttop != NULL && currenttop->next != stack->top)
			currenttop = currenttop->next;
		stack->top = currenttop;
		stack->top->next = NULL;
	}
	return (topnode);
}

t_node	*ft_top(t_stack	*stack)
{
	return (stack->top);
}

int	ft_getsize(t_stack *stack)
{
	int		count = 0;
	t_node	*current = stack->list;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	ft_isempty(t_stack *stack)
{
	return (stack->list == NULL);
}
