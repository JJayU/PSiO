#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main()
{
	std::vector<std::string> lines = { "PO12345", "PO 12345", "PZ973ND", "WE20456" };


	std::regex re(R"(P[OZ]\ *\w{5})");;

	for (auto i : lines)
	{
		std::smatch m;
		if (std::regex_match(i, m, re))
		{
			std::cout << i << std::endl;
		}
	}

	return 0;
}