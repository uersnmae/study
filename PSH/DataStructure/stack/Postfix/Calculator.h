#ifndef CALCULATOR_H
# define CALCULATOR_H

#include <stdlib.h>
#include "mystack.h"

typedef enum
{
	LEFT_PARENTHESIS	= '(', RIGHT_PARENTHESIS	= ')',
	PLUS				= '+', MINUS				= '-',
	MULTIPLY			= '*', DIVIDE				= '/',
	SPACE				= ' ', OPERAND
}	SYMBOL;

int				isnumber(char cipher);
unsigned int	get_next_token(char *expression, char *token, int *type);
int				ispriror(char operator_in_stack, char operator_in_token);
void			get_post_fix(char *infixexpression, char *postfixexpression);
double			calculator(char *postfixexpression);

#endif
