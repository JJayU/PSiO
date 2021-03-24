#include <iostream>
#include <random>
#include <ctime>
#include <vector>

int randomInt1(int min, int max)
{
    static std::default_random_engine e{ static_cast<long unsigned int> (time(0)) };
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

int main()
{
    std::vector<int> numbers(20);

    for (size_t i = 0; i < 20; i++)
    {
        numbers[i] = randomInt1(-20, 20);
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    std::cout << "---\n";

    for (auto i = numbers.begin(); i != numbers.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

    int user_input;
    std::cout << "Podaj wartosc do usuniecia: ";
    std::cin >> user_input;

    for (auto i = numbers.begin(); i != numbers.end(); i++)
    {
        if (*i == user_input)
        {
            i = numbers.erase(i);
        }
    }

    std::cout << "\nLista po usunieciu elementu:\n\n";

    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
