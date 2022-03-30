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
	int p2=bar(2, baz(3), 4);
	int p3=bar(5, baz(6), 7);
	int p4=baz(8);
    std::cout << foo(1, p2 , p3 , p4) << std::endl;
}