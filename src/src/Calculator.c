#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "parser.h"


#define BUFFER_SIZE 256


int main()    
{
	char buffer[BUFFER_SIZE];

	printf("====================== CALCULATOR ======================\n");
	printf("Enter an expression: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	
	buffer[strcspn(buffer, "\n")] = '\0';

	int tokens_count;

	int token_position = 0;
	
	Token* tokens = tokenize(buffer, &tokens_count);

	printf("Result: %g\n", calculate(tokens, &token_position));
	printf("========================================================\n");

	
	#ifdef DEBUG
		printf("\n------------ DEBUG -------------\n");
		
		for (int i = 0; i < tokens_count; i++)
		{
			printf("%s\t", tokens[i].value);
			if (tokens[i].type == TOKEN_VALUE)
			{
				printf("VALUE\n");
			}
			else printf("OPERATOR\n");
		}

		printf("--------------------------------");
	#endif // DEBUG


	free_token(tokens);

	printf("\nEnter for exit: ");
	getchar();
}

