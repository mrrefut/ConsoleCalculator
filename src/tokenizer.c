#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"


Token* tokenize(const char *buffer, int *tokens_count)
{
	Token* tokens = (Token*)calloc(strlen(buffer) + 1, sizeof(Token));
	if (tokens == NULL) return NULL;

	*tokens_count = 0;

	int buffer_count = strlen(buffer);	//symbols count

	for (int i = 0; i < buffer_count; i++)
	{
		if (buffer[i] == '\0') break;

		/*if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
		{
			tokens[*tokens_count].type = token_operator;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
		}*/

		switch (buffer[i])
		{
		case '+':
			tokens[*tokens_count].type = TOKEN_ADD;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;

		case '-':
			tokens[*tokens_count].type = TOKEN_SUBTRACT;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;

		case '*':
			tokens[*tokens_count].type = TOKEN_MULTIPLY;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;

		case '/':
			tokens[*tokens_count].type = TOKEN_DIVIDE;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;

		case '(':
			tokens[*tokens_count].type = TOKEN_LBRACKET;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;

		case ')':
			tokens[*tokens_count].type = TOKEN_RBRACKET;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
			break;
		
		}

		if (isdigit(buffer[i]))
		{
			int counter = i;	//for write int

			while (isdigit(buffer[counter]))
			{
				counter++;
			}

			int position = 0;
			for (int k = i; k < counter; k++)
			{
				tokens[*tokens_count].value[position++] = buffer[k];
			}

			tokens[*tokens_count].value[position] = '\0';

			i = counter - 1;

			tokens[*tokens_count].type = TOKEN_VALUE;

			
		}

		(*tokens_count)++;
	}

	
	return tokens;
}


void free_token(Token *token)
{
	if (token != NULL) free(token);
}
