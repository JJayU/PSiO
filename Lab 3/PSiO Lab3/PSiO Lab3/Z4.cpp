#include <iostream>
#include <random>
#include <ctime>
#include <list>

int randomInt4(int min, int max)
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
        numbers.push_back(randomInt4(-20, 20));
    }

    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    auto minimum = std::min_element(numbers.begin(), numbers.end());
    auto maximum = std::max_element(numbers.begin(), numbers.end());
    auto minmax = std::minmax_element(numbers.begin(), numbers.end());

    std::cout << "\nNajmniejszy element: " << *minimum<< "\nNajwiekszy element: " << *maximum << std::endl;
    std::cout << "\nNajmniejszy element: " << *minmax.first << "\nNajwiekszy element: " << *minmax.second << std::endl;

    return 0;
}
