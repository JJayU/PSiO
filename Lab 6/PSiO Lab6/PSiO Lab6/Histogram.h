#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

#pragma once
class Histogram
{
private:
	std::map<int, int> data;
public:
	Histogram();
	Histogram(std::map<int, int> input_data);

	void clear();
	void print();
	void emplace(const int& input_data);
	void emplace(const std::vector<int>& input_data);
	bool from_csv(std::string location, char separator, size_t column);

	std::pair<int, int> max();
	std::pair<int, int> range();
	std::vector<int> unique_bins();

	int operator[](int value);
	friend std::ostream& operator<<(std::ostream& out, const Histogram& hist);
	friend std::istream& operator>>(std::istream& in, Histogram& hist);
};

