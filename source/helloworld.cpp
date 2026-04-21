#include <array>
#include <cstdlib>   
#include <iostream>

int ggT();
int pytagoras();
int zufallszahlen();
bool flip_a_coin();
int interaktivermünzwurf();


int main()
{
	std::cout << "Moin\n"  << ggT() << "\n" << pytagoras() << "\n" << zufallszahlen() << "\n" << flip_a_coin() << interaktivermünzwurf();
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
                
        }
    }
}
}
int zufallszahlen()
{
    std::array<int, 20> numbers;
 
    for (int i = 0; i < 20; ++i) {
        numbers[i] = std::rand();
    }
 
    std::cout << "Zufallszahlen:\n";
    for (int i = 0; i < 20; ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }
    int max = numbers[0];
    for (int i = 1; i < 20; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    std::cout << "\nGroesste Zahl: " << max << "\n";
    long long sum = 0;
    for (int i = 0; i < 20; ++i) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / 20.0;
    std::cout << "Durchschnitt:  " << average << "\n";
}

bool flip_a_coin()
{
    return std::rand() % 2 == 0;
}
 
// Aufgabe 1.6.2: Interaktives Programm
int interaktivermünzwurf()
{
    std::cout << "Wie viele Muenzen sollen geworfen werden? ";
    int n = 0;
    std::cin >> n;
 
    int heads = 0;
    int tails = 0;
 
    for (int i = 0; i < n; ++i) {
        if (flip_a_coin()) {
            ++heads;
        } else {
            ++tails;
        }
    }
 
    std::cout << "#Heads Flips: " << heads << "\n";
    std::cout << "#Tails Flips: " << tails << "\n";
}