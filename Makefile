all: main

main: comp2024.c lex.yy.c main.c rec_des_parser.c
	gcc comp2024.c lex.yy.c main.c rec_des_parser.c -o main

lex.yy.c: lex.l
	flex lex.l

clean: 
	rm -f lex.yy.c main main.zip

zip: comp2024.c comp2024.h lex.l lex.yy.h main.c Makefile rec_des_parser.c rec_des_parser.h
	zip main.zip comp2024.c comp2024.h lex.l lex.yy.h main.c Makefile rec_des_parser.c rec_des_parser.h
