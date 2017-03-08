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
    if(ntoken != OPERATOR) {
	    printf("Syntax error in line %d, Expected a OPERATOR but found %s\n", yylineno, yytext);
	    return 1;
    }
    ntoken = yylex();
  
    if(ntoken != WHITESPACE) {
      printf("Syntax error in line %d, expected white space but found %s\n", yylineno, yytext);
    }
      
    ntoken = yylex(); 

    if(ntoken != INTEGER) {
      printf("Syntax error in line %d, expected integer but found %s\n", yylineno, yytext);
    }

    ntoken = yylex(); 

    if(ntoken != WHITESPACE) {
      printf("Syntax error in line %d, expected white space but found %s\n", yylineno, yytext);
    }

    ntoken = yylex(); 

    if(ntoken != INTEGER) {
      printf("Syntax error in line %d, expected integer but found %s\n", yylineno, yytext);
    }
    
  }
  return 0;
}
