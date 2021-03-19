#include <iostream>

std::string find_and_replace(std::string input_string, std::string to_replace, std::string replace_with)
{
	size_t search_from = 0;

	while (input_string.find(to_replace, search_from) != std::string::npos)
	{
		size_t beggining = input_string.find(to_replace, search_from);

		search_from = beggining + 1;

		input_string.replace(beggining, to_replace.length(), replace_with);
	}

	return input_string;
}

int main()
{
	std::string input = "Ala ma kota, kot zjadl Ale!";
	std::string output = find_and_replace(input, "kot", "hefalump");

	std::cout << output << std::endl;

	return 0;
}