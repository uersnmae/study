#include <stdlib.h>
#include "mylist.h"

t_list	*newnode(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list);
	if (!new)
		return (NULL);
	new->data = data;
	new->pnext = NULL;
	return (new);
}

void	*add_front(t_list **Head, t_list *new)
{
	if (!Head)
		return ;
	if (!(*Head))
	{
		*Head = new;
		return ;
	}
	new->pnext = *Head;
	*Head = new;
}
