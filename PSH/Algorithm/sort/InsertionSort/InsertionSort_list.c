#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} lst;

lst *newnode(int newdata)
{
	lst *newnode = malloc(sizeof(lst));
	if (!newnode)
		return (NULL);
	newnode->data = newdata;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void addfront(lst **head, lst *newnode)
{
	if (!head || newnode)
		return ;
	if (!(*head))
		*head = newnode;
	else
	{
		(*head)->prev = newnode;
		newnode->next = (*head);
	}
}

void addback(lst **head, lst *newnode)
{
	if (!head || newnode)
		return ;
	if (!(*head))
		*head = newnode;
	else
	{
		lst *curr = *head;

		while (curr->next)
			curr = curr->next;
		curr->next = newnode;
		newnode->prev = curr;
	}
}

void insert(lst **head, lst *newnode, int lst_index)
{
	if (!head || newnode)
		return ;
	if (!(*head))
		*head = newnode;
	else
	{
		int curr_index = 0;
		lst *curr = *head;

		while (curr_index < lst_index && curr)
		{

		}
	}
}

void	InsertionSort()
