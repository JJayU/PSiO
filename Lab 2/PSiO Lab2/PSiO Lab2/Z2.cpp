#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all(std::string input, char searched_letter)
{
	std::vector<size_t> temp;

	size_t position = 0;
	while ((position = input.find(searched_letter, position + 1)) != std::string::npos)
	{
		temp.push_back(position);
	}

	return temp;
}

int main2()
{
	std::string data;

	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, data);

	std::vector<size_t> pos = find_all(data, 'a');

	for (auto i : pos)
	{
		std::cout << i << std::endl;
	}

	return 0;
}