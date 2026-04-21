#include <iostream>

int ggT();
int pytagoras();


int main()
{
	std::cout << "Moin\n"  << ggT() << "\n" << pytagoras();
  return 0;
}

int ggT() {
	int current_number = 20;
	while (true) {
		bool found = true;
		for (int i = 1; i < 21; ++i) {
			if (current_number % i != 0) {
				found = false;
				break;
			}
		}
		if (found) {
			return current_number;
		}
		else {
			current_number += 20;
		}
		
	}
}
int pytagoras() {
    for (int a = 1; a < 1000; a++) {
        for (int b = a + 1; b < 1000; b++) {
            int c = 1000 - a - b;

            if (a*a + b*b == c*c) {
                std::cout << "a = " << a << ", b = " << b << ", c = " << c;
                return 0;
        }
    }
}
}