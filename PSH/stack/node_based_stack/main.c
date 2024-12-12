#include "mystack.h"

int	main(void)
{
	int		i = 0;
	int		count = 0;
	t_node	*popped;
	t_stack	*stack;
	ft_createstack(&stack);

	ft_push(stack, ft_createnode("abc"));
	ft_push(stack, ft_createnode("def"));
	ft_push(stack, ft_createnode("efg"));
	ft_push(stack, ft_createnode("hig"));

	count = ft_getsize(stack);
	printf("Size: %d, Top: %s\n\n", count, ft_top(stack)->data);
	
	for (i = 0; i < count; i++)
	{
		if (ft_isempty(stack))
			break ;
		popped = ft_pop(stack);
		printf("Popped: %s\n", popped->data);
		ft_destroynode(popped);
		if (!ft_isempty(stack))
			printf("current top: %s\n", ft_top(stack)->data);
		else
			printf("Stack is Empty\n");
	}
	ft_destroystack(stack);
	return (0);
}
