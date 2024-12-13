#include "libft.h"
#include "ExpressionTree.h"

void	free_all(char **strlist)
{
	for (int i = 0; strlist[i]; i++)
		free(strlist[i]);
	free(strlist);
	strlist = NULL;
}

int	main(void)
{
	ETNode *Root = NULL;
	char	*PostfixExpression = "7.1 13 * 5.39 21.91 - /";
	char	**ParsedPostfixExpression = ft_split(PostfixExpression, ' ');
	int		Index = 0;

	for (;ParsedPostfixExpression[Index]; Index++);
	--Index;

	ET_BuildExpressionTree(ParsedPostfixExpression, &Index, &Root);
	free_all(ParsedPostfixExpression);

	printf("Preorder ...\n");
	ET_PreorderPrintTree(Root);
	printf("\n\n");

	printf("Inorder ...\n");
	ET_InorderPrintTree(Root);
	printf("\n\n");

	printf("Postorder ...\n");
	ET_PostorderPrintTree(Root);
	printf("\n");

	printf("Evaluation Result: %f\n", ET_Evaluate(Root));
	ET_DestroyTree(Root);
	return (0);
}
