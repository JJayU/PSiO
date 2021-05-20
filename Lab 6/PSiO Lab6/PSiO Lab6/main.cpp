#include <iostream>
#include "complexnumbers.h"
#include "wektor.h"
#include "matrix.h"
\
int main()
{
    matrix<int> m;
    m = matrix<int>::Fill(3, 3, []() { return 5; });
    std::cout << "\n\n\n" << m;
}