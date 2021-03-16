#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all_spaces(std::string input)
{
	std::vector<size_t> temp;

	size_t position = -1;
	while ((position = input.find(' ', position + 1)) != std::string::npos)
	{
		temp.push_back(position);
	}

	return temp;
}

std::string find_longest_word(std::string input)
{
	input = ' ' + input + ' ';
	std::vector<size_t> spaces = find_all_spaces(input);

	size_t longest_word[2] = { 0,0 };					//first coordinate is location, second is length
	
	for (size_t i = 1; i < spaces.size(); i++)
	{
		if (spaces[i] - spaces[i - 1] - 1 > longest_word[1])
		{
			longest_word[0] = spaces[i - 1];
			longest_word[1] = spaces[i] - spaces[i - 1] - 1;
		}
	}

	return input.substr(longest_word[0] + 1, longest_word[1] + 1);
}

int main()
{
	std::string data;

	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, data);

	std::cout << "Najdluzsze slowo to: " << find_longest_word(data);

	return 0;
}