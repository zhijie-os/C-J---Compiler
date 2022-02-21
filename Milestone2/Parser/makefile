parser: parser.y parser.l parser.h
	bison -d parser.y
	flex -o parser.lex.c parser.l
	gcc -g -o $@ parser.tab.c parser.lex.c parser.c


clean:
	rm *.*.* parser
