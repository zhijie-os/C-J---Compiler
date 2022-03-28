#include <iostream>

int foo(int a, int b, int c, int d) {
	return a * b * c * d;
}

int d;

int bar(int a, int b, int c) {
        return foo(a, b, c, d-3);
}

int baz(int a) {
	d = d + 1;
	return a;
}


int main() {
	d = 10;
    std::cout << foo(1, bar(2, baz(3), 4), bar(5, baz(6), 7), baz(8)) << std::endl;
}