%{
#include "myscanner.h"
%}

%%
[0-9][0-9]*	return INTEGER;
\+		return ADD;
[ \t\n]		return WHITESPACE;
. 		printf("unexpected characted\n");

%%

int yywrap(void)
{
	return 1;
}
