#include <iostream>

uint64_t factorial(int argument)
{
	uint64_t twynik = 1;

	if (argument >= 0)
	{
		for (int i = 1; i <= argument; i++)
		{
			twynik = twynik * i;
		}
		return twynik;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int a;

	std::cout << "Silnie z jakiej liczby wyliczyc?: ";
	std::cin >> a;

	uint64_t result = factorial(a);

	std::cout << "Silnia z " << a << " to: " << result << std::endl;

	return 0;
}