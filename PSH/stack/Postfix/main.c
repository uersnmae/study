#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int	main(void)
{
	char	infixexpression[100];
	char	postfixexpression[100];
	double	result = 0.0;

	memset(infixexpression, 0, sizeof(infixexpression));
	memset(postfixexpression, 0, sizeof(postfixexpression));
	printf("Enter Infix Expression: ");
	scanf("%s", infixexpression);

	get_post_fix(infixexpression, postfixexpression);
	printf("infix: %s\nPostfix:%s\n", infixexpression, postfixexpression);
	result = calculator(postfixexpression);
	printf("Calculate Result: %f\n", result);
	return (0);
}
