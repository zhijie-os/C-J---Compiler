simplest: simplest.y simplest.l simplest.h
	bison -d simplest.y
	flex -o simplest.lex.c simplest.l
	gcc -g -o $@ simplest.tab.c simplest.lex.c simplest.c


clean:
	rm *.*.* simplest
