#include "Calculator.h"

char	NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int	isnumber(char cipher)
{
	int	i = 0;
	int	arraylength = sizeof(NUMBER);

	for (i = 0; i < arraylength; i++)

		if (cipher == NUMBER[i])
			return (1);
	return (0);
}

unsigned int	get_next_token(char *expression, char *token, int *type)
{
	unsigned int	i = 0;

	for (i = 0; expression[i]; i++)
	{
		token[i] = expression[i];
		if (isnumber(expression[i]))
		{
			*type = OPERAND;
			if (!isnumber(expression[i + 1]))
				break ;
		}
		else
		{
			*type = expression[i];
			break ;
		}
	}
	token[++i] = '\0';
	return (i);
}

int	getpriority(char operator, int instack)
{
	int	priority = -1;

	switch (operator)
	{
		case LEFT_PARENTHESIS:
		if (instack)
			priority = 3;
		else
			priority = 0;
		break ;
		case MULTIPLY:
		case DIVIDE:
		priority = 1;
		break ;
		case PLUS:
		case MINUS:
		priority = 2;
		break ;
	}
	return (priority);
}

int	ispriror(char operator_in_stack, char operator_in_token)
{
	return (getpriority(operator_in_stack, 1) > getpriority(operator_in_token, 0));
}

void	get_post_fix(char *infixexpression, char *postfixexpression)
{
	t_stack			*stack;
	char			token[32];
	int				type = -1;
	unsigned int	position = 0;
	unsigned int	length = strlen(infixexpression);

	ft_createstack(&stack);
	while (position < length)
	{
		position += get_next_token(&infixexpression[position], token, &type);
		if (type == OPERAND)
		{
			strcat(postfixexpression, token);
			strcat(postfixexpression, " ");
		}
		else if (type == RIGHT_PARENTHESIS)
		{
			while (!ft_isempty(stack))
			{
				t_node	*popped = ft_pop(stack);

				if (popped->data[0] == LEFT_PARENTHESIS)
				{
					ft_destroynode(popped);
					break ;
				}
				else
				{
					strcat(postfixexpression, popped->data);
					ft_destroynode(popped);
				}
			}
		}
		else
		{
			while (!ft_isempty(stack) && !ispriror(ft_top(stack)->data[0], token[0]))
			{
				t_node	*popped = ft_pop(stack);

				if (popped->data[0] != LEFT_PARENTHESIS)
					strcat(postfixexpression, popped->data);
				ft_destroynode(popped);
			}
			ft_push(stack, ft_createnode(token));
		}
	}
	while (!ft_isempty(stack))
	{
		t_node	*popped = ft_pop(stack);

		if (popped->data[0] != LEFT_PARENTHESIS)
				strcat(postfixexpression, popped->data);
		ft_destroynode(popped);
	}
	ft_destroystack(stack);
}

double	calculator(char *postfixexpression)
{
	t_stack	*stack;
	t_node	*result;
	double	cal_result;
	char	token[32];
	int		type= -1;
	unsigned int	read = 0;
	unsigned int	length = strlen(postfixexpression);

	ft_createstack(&stack);
	while (read < length)
	{
		read += get_next_token(&postfixexpression[read], token, &type);
		if (type == SPACE)
			continue ;
		if (type == OPERAND)
		{
			t_node	*newnode = ft_createnode(token);
			ft_push(stack, newnode);
		}
		else
		{
			char	resultstring[32];
			double	operator1, operator2, tempresult;
			t_node	*operator_node;

			operator_node = ft_pop(stack);
			operator2 = atof(operator_node->data);
			ft_destroynode(operator_node);

			operator_node = ft_pop(stack);
			operator1 = atof(operator_node->data);
			ft_destroynode(operator_node);

			switch (type)
			{
				case PLUS:		tempresult = operator1 + operator2; break;
				case MINUS:		tempresult = operator1 - operator2; break;
				case MULTIPLY:	tempresult = operator1 * operator2; break;
				case DIVIDE:	tempresult = operator1 / operator2; break;
			}
			gcvt(tempresult, 10, resultstring);
			ft_push(stack, ft_createnode(resultstring));
		}
	}
	result = ft_pop(stack);
	cal_result = atof(result->data);
	ft_destroynode(result);
	ft_destroystack(stack);
	return (cal_result);
}
