#include "libft.h"
#include "ExpressionTree.h"

ETNode *ET_CreateNode(ElementType NewData)
{
	ETNode	*NewNode = (ETNode *)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = strdup(NewData);
	if (NewNode->Data == NULL)
		return (NULL);
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

void	ET_BuildExpressionTree(char **PostfixExpression, int *Index, ETNode **Node)
{
	if (PostfixExpression[*Index] == NULL)
		return ;

	char	*Token	= PostfixExpression[*Index];
	--(*Index);

	if (strlen(Token) == 1 && !ft_isdigit(Token[0]))
	{
		switch (Token[0])
		{
			case '+': case '-': case '*': case '/':
			(*Node) = ET_CreateNode(Token);
			ET_BuildExpressionTree(PostfixExpression, Index, &(*Node)->Right);
			ET_BuildExpressionTree(PostfixExpression, Index, &(*Node)->Left);
			return ;
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
			case '+':
			Left	= ET_Evaluate(Tree->Right);
			Right	= ET_Evaluate(Tree->Left);
			Result = Left + Right;
			break;
			case '-':
			Left	= ET_Evaluate(Tree->Right);
			Right	= ET_Evaluate(Tree->Left);
			Result = Left - Right;
			break;
			case '*':
			Left	= ET_Evaluate(Tree->Right);
			Right	= ET_Evaluate(Tree->Left);
			Result = Left * Right;
			break;
			case '/':
			Left	= ET_Evaluate(Tree->Right);
			Right	= ET_Evaluate(Tree->Left);
			if (Right == 0)
			{
				fprintf(stderr, "Error: Division by zero\n");
				exit(EXIT_FAILURE);
			}
			Result = Left / Right;
			break;
		}
	}
	else
		Result = atof(Tree->Data);
	return (Result);
}
