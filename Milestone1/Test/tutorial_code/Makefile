all: flex scanner

flex: scanner.l
	flex scanner.l

scanner: scanner.h lex.yy.c scanner.c
	gcc -o lexer lex.yy.c scanner.c

clean:
	rm -rf *.yy.c lexer
