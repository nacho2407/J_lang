#include "comp2024.h"

Data mkint(int i)
{
        Data d = { TINT, .ival = i };

        return d;
}

Data mksym(str s)
{
        Data d = { TSYM, .sval = (str) malloc(strlen(s) + 1 * sizeof(char)) };

        strcpy(d.sval, s);

        return d;
}

Data mkstr(str s)
{
        Data d = mksym(s);

        d.tag = TSTR;

        return d;
}

Data cons(Data a, Data b)
{
        Pair* pair = (Pair*) malloc(sizeof(Pair));
        pair->d[0] = a;
        pair->d[1] = b;

        Data d = { TDUO, .pval = pair };

        return d;
}

void writer(Data d)
{
        switch(d.tag) {
                case TINT:
                        // printf("(INT, %d)\n", d.ival);
                        printf("%d", d.ival);
                        
                        break;
                case TSYM:
                        // printf("(SYM, %s)\n", d.sval);
                        printf("%s", d.sval);

                        free(d.sval);

                        break;
                case TSTR:
                        // printf("(STR, '%s')\n", d.sval);
                        printf("%s", d.sval);

                        free(d.sval);

                        break;
                case TNIL:
                        printf("NIL");

                        break;
                case TDUO:
                        print_list(d);

                        break;
                case TERR:
                        printf("syntax error\n");

                        break;
        }
}

void print_list(Data d)
{
        printf("(");
        
        writer(d.pval->d[0]);

        printf(" . ");

        writer(d.pval->d[1]);

        printf(")");
}

void free_list(Data l)
{
        if(l.tag != TDUO)
                return;
        
        free_list(l.pval->d[1]);

        free(l.pval);
}
