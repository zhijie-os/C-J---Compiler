#include <iostream>

#define prints(x) std::cout << x;
#define printi(x) std::cout << x;
#define printc(x) std::cout << (char)x;

int main() {
	int i;
	int j;

	i = 0;
	while (i < 10) {
		printi(i);
		prints("\n");
		j = 100;
		while (j < 110) {
			printi(j);
			prints("\n");
			if (j == 105)
				break;
			j = j + 1;
		}
		if (i == 5)
			break;
		i = i + 1;
	}
}
