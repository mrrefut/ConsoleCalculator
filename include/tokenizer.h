#ifndef TOKENIZER_H

#define TOKENIZER_H


typedef enum
{
	TOKEN_ADD,
	TOKEN_SUBTRACT,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_RBRACKET,	// )
	TOKEN_LBRACKET,	// (
	TOKEN_VALUE

}TokenType;

typedef struct
{
	TokenType type;
	char value[16];

}Token;


Token* tokenize(const char *buffer, int *tokens_count); //tokens_count may be NULL, if count of tokens not required

void free_token(Token *token);

#endif
