#include "libft.h"
#include "ExpressionTree.h"

int	main(void)
{
	ETNode *Root = NULL;
	char	PostfixExpression[20] = "7 1 * 5 2 - /";
	char	**ParsedPostfixExpression = ft_split(PostfixExpression, ' ');

	for (int i = 0; ParsedPostfixExpression[i]; i++)
		ET_BuildExpressionTree(ParsedPostfixExpression[i], &Root);

	printf("Preorder ...\n");
	ET_PreorderPrintTree(Root);
	printf("\n\n");

	printf("Postorder ...\n");
	ET_PostorderPrintTree(Root);
	printf("\n");

	printf("Evaluation Result: %f\n", ET_Evaluate(Root));
	ET_DestroyTree(Root);

	return (0);
}
