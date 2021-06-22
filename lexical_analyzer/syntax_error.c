
#include "lexical_analyzer.h"

int		syntax_error(int num)
{
	if (num == BACKSLASH_MULTI)
		printf("\\ Multiline Command doesn't work\n");
	else if (num == DQUOTES_MULTI)
		printf("\" Multiline Command doesn't work\n");
	else if (num == QUOTES_MULTI)
		printf("\' Multiline Command doesn't work\n");
	else if (num == PIPELINE_MULTI)
		printf("| Multiline Command doesn't work\n");
	else if (num == SYNTAX)
		printf("syntax error near unexpected token\n");
	return (1);
}
