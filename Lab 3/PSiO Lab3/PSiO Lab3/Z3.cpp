#include <iostream>
#include <random>
#include <ctime>
#include <list>

int randomInt3(int min, int max)
{
    static std::default_random_engine e{ static_cast<long unsigned int> (time(0)) };
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

int main()
{
    std::list<int> numbers;

    for (size_t i = 0; i < 20; i++)
    {
        numbers.push_back(randomInt3(-20, 20));
    }

    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    int user_input;
    std::cout << "Podaj wartosc do usuniecia: ";
    std::cin >> user_input;

    numbers.erase(std::find(numbers.begin(),numbers.end(),user_input));

    std::cout << "\nLista po usunieciu elementu:\n\n";

    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
