#ifndef COMP2024_H
#define COMP2024_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex.yy.h"

typedef enum _Tag
{
        TNIL,
        TINT,
        TSYM,
        TSTR,
        TDUO,
        TERR
} Tag;
typedef char* str;
typedef struct _Pair* duo;
typedef struct _Data
{
        Tag tag;
        union
        {
                int ival;
                str sval;
                duo pval;
        };
} Data;
typedef struct _Pair
{
        Data d[2];
} Pair;

Data mkint(int i);
Data mkstr(str s);
Data mksym(str s);
Data cons(Data first, Data second);
void writer(Data d);
void print_list(Data d);
void free_list(Data l);

static const Data nil = { .tag = TNIL, .pval = NULL };
static const Data err = { .tag = TERR, .pval = NULL };

/* global data */
static Data g_data;
#endif
