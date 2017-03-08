%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
#include "myscanner.h"
%}

%union {int num; char operator;}
%start line
%token INTEGER
%%

input: /**/ | input line
;

line: '\n' | rpn '\n'   {printf("%d\n",$1);}
;

rpn:  INTEGER
      | rpn rpn '+' {$$=$1+$2;}
      | rpn rpn '-' {$$=$1-$2;}
      | rpn rpn '*' {$$=$1*$2;}
;
%%

int main() (yyparse(); return 0;)
