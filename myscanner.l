%{
#include "myscanner.h"
%}

%%
[0-9][0-9]*	return INTEGER;
[\+\-\*]		return OPERATOR;
[ \t]		return;
.|\n   		{return yytext[0];}
%%

int yywrap(void)
{
	return 1;
}
