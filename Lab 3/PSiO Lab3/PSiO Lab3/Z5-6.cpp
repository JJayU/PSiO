#include <iostream>
#include <random>
#include <ctime>
#include <list>

int randomInt5(int min, int max)
{
    static std::default_random_engine e{ static_cast<long unsigned int> (time(0)) };
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

int main()
{
    std::vector<int> numbers;

    for (size_t i = 0; i < 20; i++)
    {
        numbers.push_back(randomInt5(-20, 20));
    }

    std::sort (numbers.begin(), numbers.end());

    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::cout << "\n---\n";
    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    std::sort(numbers.begin(), numbers.end(),
        [](int a, int b) { return abs(a) > abs(b); });

    std::cout << "\n---\n";
    for (auto i : numbers)
    {
        std::cout << i << std::endl;
    }

    std::cout << "\n\nLiczby wystapien: \n";
    for (int i = -20; i <= 20; i++)
    {
        int counted = std::count(numbers.begin(), numbers.end(), i);
        std::cout << i << " : " << counted << std::endl;
    }

    return 0;
}