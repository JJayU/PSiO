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

bool different_signs(double v1, double v2)
{
	return std::signbit(v1) != std::signbit(v2);
}

double zero_r(double x1, double x2, std::vector<double> p)
{
	double x_mid = (x1 + x2) / 2.0;

	double y_x1 = poly(x1, p);
	double y_mid = poly(x_mid, p);
	double y_x2 = poly(x2, p);

	if (x1 - x2 < 1e-9)
	{
		return x_mid;
	}
	else if (different_signs(y_x1, y_mid))
	{
		return zero_r(x1, x_mid, p);
	}
	else if (different_signs(y_x2, y_mid))
	{
		return zero_r(x1, x_mid, p);
	}

	return 0;
}

std::vector<double> zero(double x_min, double x_max, std::vector<double> p ,double step)
{
	std::vector<double> values;

	size_t steps = (x_max - x_min) / step;

	for (size_t i = 0; i < steps; i++)
	{
		double x1 = x_min + i * step;
		double x2 = x_min + (i + 1) * step;

		double x1_val = poly(x1, p);
		double x2_val = poly(x2, p);

		if (different_signs(x1_val, x2_val))
		{
			std::cout << "Znaleziono miejsce zerowe w przedziale " << x1 << " " << x2 << std::endl;

			double x_0 = zero_r(x1, x2, p);
			values.push_back(x_0);
		}
	}

	return values;

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

	std::cout << "Miejsca zerowe: ";
	std::vector<double> roots = zero(-100, 100, p, 1);

	for (auto i : roots)
	{
		std::cout << i << std::endl;
	}

	return 0;
}