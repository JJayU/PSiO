#include <iostream>
#include <vector>

void min_max(std::vector<double>& values, double& min, double& max)
{
    min = values[0];
    max = values[0];

    for (auto i : values)
    {
        if (i > max)
        {
            max = i;
        }
        if (i < min)
        {
            min = i;
        }
    }
}

int main()
{
    std::vector<double> wektor2 = { 2,5,2,7,1,10,8 };
    double min, max;

    min_max(wektor2, min, max);
    std::cout << min << " " << max;

    return 0;
}