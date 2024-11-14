#include "rec_des_parser.h"

void rec_des_parser(void)
{
        for(int lex = yylex(); !lex; lex = yylex()) {
                switch(lex) {
                        case ILITERAL:
                                g_data = mkint(atoi(yytext));

                                break;
                        case SYMBOL:
                                g_data = mksym(yytext);

                                break;
                        case LIST_B:
                                g_data = list();

                                break;
                        case STRING:
                                g_data = mkstr(yytext);

                                break;
                        // default:
                        //         g_data = err;

                        //         break;
                }

                writer(g_data);
        }
}

static Data list(void)
{
        Data first = nil;

        int lex = yylex();
        switch(lex) {
                case ILITERAL:
                        first = mkint(atoi(yytext));

                        break;
                case SYMBOL:
                        first = mksym(yytext);

                        break;
                case LIST_B:
                        first = list();

                        break;
                case LIST_E:
                        return nil;

                        break;
                case STRING:
                        first = mkstr(yytext);

                        break;
                // default:
                //         g_data = err;

                //         break;
        }

        return cons(first, list());
}
