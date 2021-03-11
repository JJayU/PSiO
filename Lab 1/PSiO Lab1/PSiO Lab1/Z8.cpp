#include <iostream>

int gcd(int a, int b)
{
	int c;
	
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

int main()
{
	int pierwsza, druga;
	std::cout << "Podaj pierwsza liczbe: ";
	std::cin >> pierwsza;
	std::cout << "Podaj druga liczbe: ";
	std::cin >> druga;

	std::cout << "NWD tych liczb to: " << gcd(pierwsza, druga) << std::endl;

	return 0;
}