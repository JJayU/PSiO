#include <iostream>
#include <vector>

void fill_progressive(std::vector<int> &param)
{
    for (size_t i = 1; i <= param.size(); i++)
    {
        param[i - 1] = i;
    }
}

void print_vector(const std::vector<int> &param)
{
    for (auto i : param)
    {
        std::cout << i << ", ";
    }
}

int main()
{
    size_t dlugosc;
    do
    {
        std::cout << "Podaj rozmiar wektora: ";
        std::cin >> dlugosc;
    } while (dlugosc < 1);

    std::vector<int> wektor(dlugosc);

    fill_progressive(wektor);
    print_vector(wektor);

    return 0;
}