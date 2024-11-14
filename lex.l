%{
#define ILITERAL 301
#define SYMBOL 302
#define LIST_B 303
#define LIST_E 304
#define STRING 305
#define OPRTR 306
%}
iliteral        [+-]?[0-9]+
symbol  [a-zA-Z][a-zA-Z0-9]*
list_begin      \(
list_end        \)
whitespace      [ \t\n]+
comment ;.*\n
string  \".*\"
operator        [\+\-\/\*]
end     \0
%%
{iliteral} {
        return ILITERAL;
}
{symbol} {
        return SYMBOL;
}
{list_begin} {
        return LIST_B;
}
{list_end} {
        return LIST_E;
}
{whitespace} {
        /* Do Nothing */
}
{comment} {
        /* Do Nothing */
}
{string} {
        return STRING;
}
{operator} {
        return OPRTR;
}
{end} {
        return 0;
}
%%
int yywrap()
{
        return 1;
}
