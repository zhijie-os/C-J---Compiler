main: main.o scanner.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -o $@ -c $<

%.cpp: %.l
	flex -o $@ $<

clean:
	rm *.o main