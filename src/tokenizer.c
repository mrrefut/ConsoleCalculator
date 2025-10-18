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

		if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
		{
			tokens[*tokens_count].type = TOKEN_OPERATOR;
			tokens[*tokens_count].value[0] = buffer[i];
			tokens[*tokens_count].value[1] = '\0';
		}
		else if (isdigit(buffer[i]))
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
		else continue;

		(*tokens_count)++;
	}

	
	return tokens;
}


void free_token(Token *token)
{
	if (token != NULL) free(token);
}