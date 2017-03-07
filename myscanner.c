#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *vals[] = {NULL, };

int main(void)
{
  int ntoken, vtoken;

  ntoken = yylex();
  while(ntoken) {
     printf("%d\n", ntoken);
     if(yylex() != WHITESPACE) {
	printf("Syntax error in line %d, Expected a space but found %s\n", yylineno, yytext);
	return 1;
     }
     vtoken = yylex();
     switch(ntoken) {
     case INTEGER:
     case ADD:
     break;
     default:
     break;
     }
      
     ntoken = yylex(); 
  }
  return 0;
}
