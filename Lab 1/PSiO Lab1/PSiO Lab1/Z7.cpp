#include <iostream>

void draw_square(int size, bool left_diagonal, bool right_diagonal)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 || i == size - 1)
			{
				std::cout << "#";
			}
			else
			{
				if (j == 0 || j == size - 1)
				{
					std::cout << "#";
				}
				else
				{
					if (left_diagonal && i == j)
					{
						std::cout << "#";
					}
					else if (right_diagonal && i == size - j - 1)
					{
						std::cout << "#";
					}
					else
					{
						std::cout << " ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "Podaj rozmiar kwadratu: ";
	int rozmiar;
	do
	{
		std::cin >> rozmiar;
	} while (rozmiar < 1);

	draw_square(rozmiar, 1, 1);

	return 0;
}