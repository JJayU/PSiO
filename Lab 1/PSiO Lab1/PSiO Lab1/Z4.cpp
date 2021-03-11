#include <iostream>

uint64_t factorial_r(int argument)
{
	if (argument < 0)
	{
		return 0;
	}
	else if (argument == 0)
	{
		return 1;
	}
	else
	{
		return (argument*factorial_r(argument - 1));
	}
}

int main()
{
	int a;

	std::cout << "Silnie z jakiej liczby wyliczyc?: ";
	std::cin >> a;

	uint64_t result = factorial_r(a);

	std::cout << "Silnia z " << a << " to: " << result << std::endl;

	return 0;
}