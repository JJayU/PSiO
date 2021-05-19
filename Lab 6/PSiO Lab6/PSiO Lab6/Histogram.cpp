#include "Histogram.h"

Histogram::Histogram()
{
	data = {};
}

Histogram::Histogram(std::map<int, int> input_data)
{
	data = input_data;
}

void Histogram::clear()
{
	data.clear();
}

void Histogram::print()
{
	std::cout << "\nZawartosc histogramu:\n";
	for (auto i : data)
	{
		std::cout << i.first << " : " << i.second << std::endl;
	}
}

void Histogram::emplace(const int& a)
{
	data[a]++;
}

void Histogram::emplace(const std::vector<int>& input_data)
{
	for (auto i : input_data)
	{
		data[i]++;
	}
}

int Histogram::operator[](int value)
{
	return data[value];
}

std::pair<int, int> Histogram::max()
{
	using pairtype = std::pair<int, int>;

	std::pair<int, int> tresult;

	auto t = std::max_element(data.begin(), data.end(), 
		[](pairtype a, pairtype b) { return a.second < b.second; }
	);

	tresult.first = t->first;
	tresult.second = t->second;

	return tresult;
}

std::pair<int, int> Histogram::range()
{
	std::pair<int, int> tresult;
	tresult.first = data.begin()->first;
	tresult.second = data.rbegin()->first;

	return tresult;
}

std::vector<int> Histogram::unique_bins()
{
	std::vector<int> tvect;
	for (auto i : data)
	{
		if (i.second > 0)
		{
			tvect.push_back(i.first);
		}
	}

	return tvect;
}

std::ostream& operator<<(std::ostream& out, const Histogram& hist)
{
	out << "\nZawartosc histogramu:\n";
	for (auto i : hist.data)
	{
		out << i.first << " : " << i.second << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Histogram& hist)
{
	std::size_t count;
	std::cout << "Podaj liczbe pol: ";
	in >> count;

	for (size_t i = 0; i < count; i++)
	{
		int tinput;
		in >> tinput;
		hist.emplace(tinput);
	}

	return in;
}

bool Histogram::from_csv(std::string location, char separator, size_t column)
{
	std::fstream file;
	file.open(location, std::ios_base::in);

	if (!file.good())
	{
		return 0;
	}

	std::string tstring;
	std::getline(file, tstring);

	while (getline(file, tstring))
	{
		size_t tstring_l = tstring.length();
		size_t act_col = 0;
		std::string val = "";
		for (size_t i = 0; i < tstring_l; i++)
		{
			if (tstring[i] == separator)
			{
				act_col++;
				continue;
			}
			if (act_col == column)
			{
				val += tstring[i];
			}
		}
		int intval = std::stoi(val);
		emplace(intval);
	}
	
	return 1;
}