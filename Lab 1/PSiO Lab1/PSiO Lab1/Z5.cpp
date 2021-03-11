#include <iostream>

bool is_prime(int liczba)
{
	int dzielniki = 0;

	for (int i = 2; i < (liczba / 2); i++)
	{
		if (liczba % i == 0)
		{
			dzielniki++;
			break;
		}
	}

	if (dzielniki == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::cout << "Podaj liczbe: ";
	int prime_or_not_prime;
	std::cin >> prime_or_not_prime;

	if (is_prime(prime_or_not_prime))
	{
		std::cout << "Licza " << prime_or_not_prime << " jest liczba pierwsza" << std::endl;
	}
	else
	{
		std::cout << "Licza " << prime_or_not_prime << " nie jest liczba pierwsza" << std::endl;
	}

	int poczatek, koniec;

	std::cout << "Podaj poczatek zakresu: ";
	std::cin >> poczatek;
	do
	{
		std::cout << "Podaj koniec zakresu: ";
		std::cin >> koniec;
	} while (koniec <= poczatek);

	for (int i = poczatek; i <= koniec; i++)
	{
		if (i % 2 != 0 || i == 2)
		{
			if (is_prime(i))
			{
				std::cout << i << std::endl;
			}
		}
	}

	return 0;
}