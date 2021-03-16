#include <iostream>
#include <string>

bool is_palindrome(std::string input)
{
    std::string input_fixed = "";
    std::string flipped = "";

    for (size_t i = 0; i < input.length(); i++)
    {
        while (input[i] == ' ')
        {
            i++;
        }
        input_fixed += std::tolower(input[i]);
    }

    for (size_t i = input_fixed.length() - 1; i > 0; i--)
    {
        flipped += input_fixed[i];
    }
    flipped += input_fixed[0];

    if (input_fixed == flipped)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main1()
{
    std::string slowo;

    std::cout << "Podaj wyrazenie: ";
    std::getline(std::cin, slowo);

    if (is_palindrome(slowo))
    {
        std::cout << "Wyrazenie \"" << slowo << "\" jest palindromem\n";
    }
    else
    {
        std::cout << "Wyrazenie \"" << slowo << "\" nie jest palindromem\n";
    }

    return 0;
}