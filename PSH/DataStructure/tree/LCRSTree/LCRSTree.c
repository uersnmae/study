#include "LCRSTree.h"

LCRSNode	*LCRS_CreateNode(ElementType NewData)
{
	LCRSNode	*NewNode = (LCRSNode *)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;

	return (NewNode);
}

void	LCRS_DestroyNode(LCRSNode *Node)
{
	free(Node);
}

void	LCRS_DestroyTree(LCRSNode *Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);
	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);
	Root->LeftChild = NULL;
	Root->RightSibling = NULL;
	LCRS_DestroyNode(Root);
}

void	LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child)
{
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else
	{
		LCRSNode *TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;
		TempNode->RightSibling = Child;
	}
}

void	LCRS_PrintTree(LCRSNode *Node, int Depth)
{
	int	i = 0;

	for (i = 0; i < Depth - 1; i++)
		printf("   ");
	if (Depth > 0)
		printf("+--");
	printf("%c\n", Node->Data);
	if (Node->LeftChild)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

void	LCRS_PrintNodesAtLevel(LCRSNode *Node, int Level)
{
	LCRSNode	*curr = Node;
	int			_Level = -1;

	if (curr == NULL)
	{
		printf("Tree is Empty\n");
		return ;
	}
	if (Level < 0)
	{
		printf("Invalid Level\n");
		return ;
	}
	while ((++_Level < Level) && curr)
		curr = curr->LeftChild;
	while (curr)
	{
		printf("%c ", curr->Data);
		curr = curr->RightSibling;
	}
}
