#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

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

	std::regex re(R"(( \d{9}\s)|( \+\d{11}\s)|( \d{13})|( \(\d{3}\)\ *\d{7})|( \d{2}[ -]\d{2}[ -]\d{2}[ -]\d{3})|( \d{2}[ -]\d{3}[ -]\d{2}[ -]\d{2})|( \d{3}[ -]\d{2}[ -]\d{2}[ -]\d{2})|( \+\d{2} \d{3}[ -]\d{2}[ -]\d{2}[ -]\d{2}))");
	std::smatch m;

	while (std::regex_search(full_text, m, re))
	{
		std::cout << m[0] << std::endl;
		full_text = m.suffix();
	}

	return 0;
}