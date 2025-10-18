#include <stdlib.h>
#include "tokenizer.h"
#include "parser.h"

 static double parse_num_or_brackets(Token *expression, int *pos)	//find () or num
{
	if (expression[*pos].type == TOKEN_VALUE)
	{
		double value = atof(expression[*pos].value);

		(*pos)++;

		return value;
	}
	else if (expression[*pos].type == TOKEN_OPERATOR && expression[*pos].value[0] == '(')
	{
		(*pos)++;

		double result = parse_addsub(expression, pos);

		if (expression[*pos].type == TOKEN_OPERATOR && expression[*pos].value[0] == ')')
		{
			(*pos)++;

			return result;
		}
	}
	else return 0;
}

static double parse_muldiv(Token *expression, int *pos)	//find * or /
{
	double value_left = parse_num_or_brackets(expression, pos);

	while(expression[*pos].type == TOKEN_OPERATOR && 
		(expression[*pos].value[0] == '*' || expression[*pos].value[0] == '/'))
	{
		char operation = expression[*pos].value[0];

		(*pos)++;

		double value_right = parse_num_or_brackets(expression, pos);

		if (operation == '*') value_left *= value_right;
		if (operation == '/') value_left /= value_right;
	}

	return value_left;
}

static double parse_addsub(Token *expression, int *pos)	//find + or -
{
	double value_left = parse_muldiv(expression, pos);
	
	while(expression[*pos].type == TOKEN_OPERATOR && 
		(expression[*pos].value[0] == '+' || expression[*pos].value[0] == '-'))
	{
		char operation = expression[*pos].value[0];

		(*pos)++;

		double value_right = parse_muldiv(expression, pos);

		if (operation == '+') value_left += value_right;
		if (operation == '-') value_left -= value_right;
 	}

	return value_left;
}

double calculate(Token* expression, int* pos) 
{ 
	return parse_addsub(expression, pos); 
}