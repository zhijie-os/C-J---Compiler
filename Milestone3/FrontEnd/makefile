


main: parser.y scanner.l parser.h
	bison -t -v -d parser.y
	flex  scanner.l
	g++ -g -o $@ parser.bison.cpp scanner.flex.cpp main.cpp AST.cpp semantic.cpp


clean:
	rm *.*.* main
