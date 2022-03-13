


parser: parser.y scanner.l parser.h main.cpp
	bison -t -v -d parser.y
	flex  -o  scanner.lex.cpp scanner.l
	g++ -g -o $@ parser.tab.c scanner.lex.cpp main.cpp


clean:
	rm *.*.* parser parser.output
