#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, int> map;

	std::fstream file;
	file.open("files/license.txt", std::ios::in);

	std::regex re(R"([^\w\d]*([a-zA-Z]+))");

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string word;
			file >> word;

			std::smatch m;
			bool res = std::regex_match(word, m, re);

			if (res)
			{
				word = m[1];

				std::transform(word.begin(), word.end(), word.begin(),
					[](unsigned char c) -> unsigned char { return std::tolower(c); });

				auto find = map.find(word);
				if (find != map.end())
				{
					map[word] += 1;
				}
				else
				{
					map.emplace(word, 1);
				}
			}
		}
	}

	file.close();

	/*
	for (auto i : map)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
	*/

	std::vector<std::pair<std::string, int>> map2;

	std::copy(map.begin(), map.end(), std::back_inserter(map2));

	std::sort(map2.begin(), map2.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
			return a.second > b.second;
		});

	for (auto i : map2)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}

	std::fstream output;
	output.open("output_zk1.txt", std::ios::out);

	for (auto i : map2)
	{
		output << i.second << " " << i.first << std::endl;
	}
	
	output.close();

	return 0;
}