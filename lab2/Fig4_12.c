/* Code of Figure 4.12, pages 105-107 from
   Kenneth C. Louden, Programming Languages
   Principles and Practice 2nd Edition
   Copyright (C) Brooks-Cole/ITP, 2003
   Operators are ??? associative.
   Precedence ???  ::Highest -->Lowest
*/
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int token; /* holds the current input character for the parse */

/* declarations to allow arbitrary recursion */
void command(void);
int expr(void);
int average(void);
int term(void);
int factor(void);
int number(void);
int digit(void);

void error(void)
{ printf("parse error\n");
  exit(1);
}

void getToken(void)
{ /* tokens are characters */
  token = getchar();
  if (token == '\t' || token ==' ') getToken();  /* removes whitespaces on input line */}

void  match(char c)
{ if (token == c) getToken();
  else error();
}

void command(void)
/* command -> expr '\n' */
{ int result = expr();
  if (token == '\n') /* end the parse and print the result */
     printf("The result is: %d\n",result);
  else error();
}

int expr(void)
/* expr -> term |expr '+' term */
/* expr -> term { '+' term } */
{
  int result = average();
  while (token == '+')
  { match('+');
    result += average();
  }
  return result;
}

int average(void)
{
	int result = term();
	while (token == '@')
	{match('@');
    result = (result + term()) / 2;
	}
	return result;
}


int term(void)
/* term -> factor | term '*' factor  */
/* term -> factor { '*' factor } */
{ int result = factor();
  while (token == '*')
  { match('*');
    result *= factor();
  }
  return result;
}

int factor(void)
/* factor -> '(' expr ')' | number */
{ int result;
  if (token == '(')
  { match('(');
    result = expr();
    match(')');
  }
  else
    result = number();
  return result;
}

int number(void)
/* number -> digit | number digit  */
/* number -> digit { digit } */
{ int result = digit();
  while (isdigit(token))
  /* the value of a number with a new trailing digit
    is its previous value shifted by a decimal place
    plus the value of the new digit
  */
    result = 10 * result + digit();
  return result;
}

int digit(void)
/* digit -> '0' | '1' | '2' | '3' | '4'
                | '5' | '6' | '7' | '8' | '9' */
{ int result;
  if (isdigit(token))
  { /* the numeric value of a digit character
       is the difference between its ascii value and the
       ascii value of the character '0'
    */
    result = token - '0';
    match(token);
  }
  else
    error();
  return result;
}

void parse(void)
{ getToken(); /* get the first token */
  command(); /* call the parsing procedure for the start symbol */
}

int main()
{ parse();
  return 0;
}

