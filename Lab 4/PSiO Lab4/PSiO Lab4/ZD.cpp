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
	std::string full_text = "";

	std::fstream file;
	file.open("files/numery.html", std::ios::in);

	if (file.is_open())
	{
		std::stringstream str_stream;
		str_stream << file.rdbuf();
		full_text = str_stream.str();
	}

	std::regex re(R"()");

	return 0;
}