#include <iostream>
#include <iomanip>
#include <cmath>

double leibniz_pi(double dokladnosc)
{
	double aktualny_wyraz = 1;
	int mianownik = 1;
	double wynik = 0;
	bool dodawanie = true;

	while (aktualny_wyraz > dokladnosc)
	{
		if (dodawanie)
		{
			wynik += aktualny_wyraz;
		}
		else
		{
			wynik -= aktualny_wyraz;
		}
		dodawanie = !dodawanie;

		mianownik += 2;
		aktualny_wyraz = 1.0 / mianownik;
	}

	return wynik*4.0;
}

int main()
{
	double stop_at;

	std::cout << "Podaj dokladnosc: ";
	std::cin >> stop_at;
	std::cout << "Wynik: " << std::setprecision(30) << leibniz_pi(stop_at);
	//std::cout << "Blad:  " << std::setprecision(30) << leibniz_pi(stop_at) - M_PI;
	return 0;
}