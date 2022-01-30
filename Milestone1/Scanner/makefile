scanner: lex.yy.c
	gcc -o scanner lex.yy.c

lex.yy.c: scanner.l
	flex scanner.l

clean: 
	rm *.yy.c
