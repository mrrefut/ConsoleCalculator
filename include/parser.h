#ifndef PARSER_H

#define PARSER_H

static double parse_num_or_brackets(Token* expression, int* pos);
static double parse_muldiv(Token* expression, int* pos);
static double parse_addsub(Token* expression, int* pos);
double calculate(Token* expression, int* pos);

#endif
