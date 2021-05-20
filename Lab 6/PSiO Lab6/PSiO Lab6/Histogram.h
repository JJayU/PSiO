#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>

#pragma once

template <typename T>
class Histogram
{
private:
	std::map<T, int> data;
public:
	Histogram<T>();
	Histogram<T>(std::map<T, int> input_data);

	void clear();
	void print();
	void emplace(T input_data);
	void emplace(const std::vector<T>& input_data);
	bool from_csv(std::string location, char separator, size_t column);

	std::pair<T, int> max();
	std::pair<T, T> range();
	std::vector<T> unique_bins();

	static Histogram<T> generate(size_t count, int min, int max);
	static Histogram<T> generate(size_t count, T (*function)());

	int operator[](T value);

	friend std::ostream& operator<<(std::ostream& out, const Histogram<T>& hist);
	friend std::istream& operator>>(std::istream& in, Histogram<T>& hist);
};

template <typename T>
Histogram<T>::Histogram()
{
	data = {};
}

template <typename T>
Histogram<T>::Histogram(std::map<T, int> input_data)
{
	data = input_data;
}

template <typename T>
void Histogram<T>::clear()
{
	data.clear();
}

template <typename T>
void Histogram<T>::print()
{
	std::cout << "\nZawartosc histogramu:\n";
	for (auto i : data)
	{
		std::cout << i.first << " : " << i.second << std::endl;
	}
}

template <typename T>
void Histogram<T>::emplace(T a)
{
	data[a]++;
}

template <typename T>
void Histogram<T>::emplace(const std::vector<T>& input_data)
{
	for (auto i : input_data)
	{
		data[i]++;
	}
}

template <typename T>
int Histogram<T>::operator[](T value)
{
	return data[value];
}

template <typename T>
std::pair<T, int> Histogram<T>::max()
{
	using pairtype = std::pair<T, int>;

	std::pair<T, int> tresult;

	auto t = std::max_element(data.begin(), data.end(),
		[](pairtype a, pairtype b) { return a.second < b.second; }
	);

	tresult.first = t->first;
	tresult.second = t->second;

	return tresult;
}

template <typename T>
std::pair<T, T> Histogram<T>::range()
{
	std::pair<T, T> tresult;
	tresult.first = data.begin()->first;
	tresult.second = data.rbegin()->first;
	return tresult;
}

template <typename T>
std::vector<T> Histogram<T>::unique_bins()
{
	std::vector<T> tvect;

	for (auto i : data)
	{
		if (i.second > 0)
		{
			tvect.push_back(i.first);
		}
	}

	return tvect;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Histogram<T>& hist)
{
	out << "\nZawartosc histogramu:\n";

	for (auto i : hist.data)
	{
		out << i.first << " : " << i.second << std::endl;
	}

	return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Histogram<T>& hist)
{
	size_t count;
	std::cout << "Podaj liczbe pol: ";
	in >> count;

	for (size_t i = 0; i < count; i++)
	{
		T tinput;
		in >> tinput;
		hist.emplace(tinput);
	}

	return in;
}

template <typename T>
bool Histogram<T>::from_csv(std::string location, char separator, size_t column)
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

		//dziala tylko dla int
		if (std::is_same<T, int>())
		{
			int intval = std::stoi(val);
			data[intval]++;
		}
		else if (std::is_same<T, std::string>())
		{
			//val.
			//data[val]++;
		}
		else if (std::is_same<T, double>())
		{
			//double doubleval = std::stod(val);
			//data[doubleval]++;
		}
		else if (std::is_same<T, float>())
		{
			//double floatval = std::stof(val);
			//data[floatval]++;
		}
		else
		{
			throw "Unsupported typename!";
		}
	}

	return 1;
}

template <typename T>
Histogram<T> Histogram<T>::generate(size_t count, int min, int max)
{
	if (!std::is_same <T, double>)
	{
		throw "Unsupported typename!";
	}

	Histogram<T> thist;

	srand(time(NULL));

	for (size_t i = 0; i < count; i++)
	{
		thist.emplace(min + rand() % (abs(max) + abs(min)));
	}

	return thist;
}

template <typename T>
Histogram<T> Histogram<T>::generate(size_t count, T(*function)())
{
	Histogram<T> thist;

	for (size_t i = 0; i < count; i++)
	{
		thist.emplace(function());
	}

	return thist;
}
