#ifndef LEX_YY_H
#define LEX_YY_H

#define ILITERAL 301
#define SYMBOL 302
#define LIST_B 303
#define LIST_E 304
#define STRING 305
#define OPRTR 306

extern int yylex(void);
extern int yyinput(void);

extern char* yytext;
#endif
