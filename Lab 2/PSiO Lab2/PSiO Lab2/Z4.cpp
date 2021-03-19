#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

std::vector<std::string> split(std::string input_text, char splitter = ' ')
{
	std::vector<std::string> temp_output;
	size_t previous_word_beginning = 0;
	char previous_character = input_text[0];

	for (size_t i = 1; i < input_text.length(); i++)
	{
		if (input_text[i] == splitter || i == input_text.length() - 1)
		{
			if (previous_character != splitter)
			{
				temp_output.push_back(input_text.substr(previous_word_beginning, (i == input_text.length() - 1 ? i-previous_word_beginning + 1 : i - previous_word_beginning)));
			}
			previous_word_beginning = i + 1;
			previous_character = input_text[i];
		}
		else
		{
			previous_character = input_text[i];
		}
	}

	return temp_output;
}

int main()
{
	std::string data = "Ala ma kota";
	std::string csv = "Mount Everest,8848,1953";

	std::vector<std::string> splitted_text = split(data);
	std::vector<std::string> splitted_csv = split(csv, ',');

	for (auto i : splitted_text)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;

	for (auto i : splitted_csv)
	{
		std::cout << i << std::endl;
	}

	return 0;
}