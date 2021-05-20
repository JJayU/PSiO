#pragma once
#include <vector>
#include <iostream>

template <typename T>
class matrix
{
private:
	std::vector<std::vector<T>> data;
public:
	matrix<T>()
	{
		data = {};
	}

	matrix<T>(size_t size_x, size_t size_y)
	{
		for (size_t i = 0; i < size_y; i++)
		{
			std::vector<T> tvect;
			for (size_t j = 0; j < size_x; j++)
			{
				tvect.push_back(0);
			}
			data.push_back(tvect);
		}
	}

	matrix<T>(std::vector<std::vector<T>> input_data)
	{
		data = input_data;
	}

	friend std::istream& operator>>(std::istream& in, matrix<T>& a)
	{
		a.data = {};

		std::cout << "Podaj wymiar: ";
		size_t size;
		in >> size;

		for (size_t i = 0; i < size; i++)
		{
			std::vector<T> tvect;
			for (size_t j = 0; j < size; j++)
			{
				T b;
				in >> b;
				tvect.push_back(b);
			}
			a.data.push_back(tvect);
		}

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, matrix<T> a)
	{
		for (size_t i = 0; i < a.data.size(); i++)
		{
			for (size_t j = 0; j < a.data[0].size(); j++)
			{
				out << a.data[i][j] << " ";
			}
			out << std::endl;
		}

		return out;
	}

	static matrix<T> Eye(size_t size_x, size_t size_y)
	{
		matrix<T> tmatr;

		for (size_t i = 0; i < size_y; i++)
		{
			std::vector<T> tvect;
			for (size_t j = 0; j < size_x; j++)
			{
				if (i == j)
				{
					tvect.push_back(1);
				}
				else
				{
					tvect.push_back(0);
				}
				
			}
			tmatr.data.push_back(tvect);
		}

		return tmatr;
	}

	static matrix<T> Fill(size_t size_x, size_t size_y, T(*function)())
	{
		matrix<T> tmatr;

		for (size_t i = 0; i < size_y; i++)
		{
			std::vector<T> tvect;
			for (size_t j = 0; j < size_x; j++)
			{
				tvect.push_back(function());
			}
			tmatr.data.push_back(tvect);
		}

		return tmatr;
	}
};

