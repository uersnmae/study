#include "libft.h"
#include "ExpressionTree.h"

ETNode *ET_CreateNode(ElementType NewData)
{
	ETNode	*NewNode = (ETNode *)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = malloc(sizeof(NewData));
	strcpy(NewNode->Data, NewData);
	return (NewNode);
}

void	ET_DestroyNode(ETNode *Node)
{
	free(Node->Data);
	free(Node);
}

void	ET_DestroyTree(ETNode *Root)
{
	if (Root == NULL)
		return ;
	ET_DestroyTree(Root->Left);
	ET_DestroyTree(Root->Right);
	ET_DestroyNode(Root);
}

void	ET_PreorderPrintTree(ETNode *Node)
{
	if (Node == NULL)
		return ;
	printf(" %s", Node->Data);
	ET_PreorderPrintTree(Node->Left);
	ET_PreorderPrintTree(Node->Right);
}

void	ET_InorderPrintTree(ETNode *Node)
{
	if (Node == NULL)
		return ;
	printf("(");
	ET_InorderPrintTree(Node->Left);
	printf("%s", Node->Data);
	ET_InorderPrintTree(Node->Right);
	printf(")");
}

void	ET_PostorderPrintTree(ETNode *Node)
{
	if (Node == NULL)
		return ;
	ET_PostorderPrintTree(Node->Left);
	ET_PostorderPrintTree(Node->Right);
	printf(" %s", Node->Data);
}

void	ET_BuildExpressionTree(char *PostfixExpression, ETNode **Node)
{
	char	*Token	= PostfixExpression;

	if (strlen(Token->Data) == 1 && !ft_isdigit(Token->Data[0]))
	{
		switch (*Token)
		{
			case '+': case '-': case '*': case '/':
			(*Node) = ET_CreateNode(Token);
			ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
			ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
			break ;
		}
	}
	else
		(*Node) = ET_CreateNode(Token);
}

double	ET_Evaluate(ETNode *Tree)
{
	double	Left 	= 0;
	double	Right	= 0;
	double	Result 	= 0;

	if (Tree == NULL)
		return (0);
	if (strlen(Tree->Data) == 1 && !ft_isdigit(Tree->Data[0]))
	{
		switch (*(Tree->Data))
		{
			case '+': case '-': case '*': case '/':
			Left	= ET_Evaluate(Tree->Right);
			Right	= ET_Evaluate(Tree->Left);

			if (*(Tree->Data) == '+') Result = Left + Right;
			else if (*(Tree->Data) == '-') Result = Left - Right;
			else if (*(Tree->Data) == '*') Result = Left * Right;
			else if (*(Tree->Data) == '/') Result = Left / Right;
			break ;
		}
	}
	else
		Result = atof(Tree->Data);
	return (Result);
}
