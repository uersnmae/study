#ifndef MYSTACK_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MYSTACK_H

typedef struct tagNode
{
	char			*data;
	struct tagNode	*next;
}	t_node;

typedef struct tagLinkedListStack
{
	t_node	*list;
	t_node	*top;
}	t_stack;

void	ft_createstack(t_stack **stack);
void	ft_destroystack(t_stack *stack);
t_node	*ft_createnode(char *newdata);
void	ft_destroynode(t_node *node);
void	ft_push(t_stack *stack, t_node *newnode);
t_node	*ft_pop(t_stack *stack);
t_node	*ft_top(t_stack	*stack);
int	ft_getsize(t_stack *stack);
int	ft_isempty(t_stack *stack);

#endif
