#include <iostream>
#include "Histogram.h"

int main()
{
    Histogram hist;
    hist.from_csv(R"(wyniki.csv)", ',', 4);
    std::cout << hist;
    std::pair<int, int> b = hist.range();
    std::cout << b.first << " - " << b.second;
    std::vector<int> a = hist.unique_bins();

}