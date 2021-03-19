#include <iostream>
#include <vector>
#include <math.h>

std::vector<double> get_poly(size_t elements_count)
{
	std::vector<double> temp_vec;

	for (size_t i = 0; i < elements_count; i++)
	{
		temp_vec.push_back(0);
		std::cout << "Podaj element " << i + 1 << ": ";
		std::cin >> temp_vec[i];
	}

	return temp_vec;
}

double poly(double x, std::vector<double> p)
{
	double result = 0;

	for (size_t i = 0; i < p.size(); i++)
	{
		result += p[i] * pow(x, i);
	}

	return result;
}

int main()
{
	size_t n;

	std::cout << "Podaj liczbe elementow: ";
	std::cin >> n;

	std::vector<double> p = get_poly(n);

	double x;
	std::cout << "Podaj x: ";
	std::cin >> x;
	std::cout << "Wynik: " << poly(x, p) << std::endl;

	return 0;
}