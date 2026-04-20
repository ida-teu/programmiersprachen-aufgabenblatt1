#include <iostream>

int ggT();

int main()
{
	std::cout << "Moin\n" << ggT();
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