#pragma once
#include <vector>
#include <iostream>

template <typename T>
class wektor
{
private:
	std::vector<T> dane;
public:
	wektor(size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			dane.push_back(0);
		}
	}

	wektor(std::vector<T> input_data)
	{
		dane = input_data;
	}

	friend std::ostream& operator<<(std::ostream& out, wektor<T> a)
	{
		out << "( ";
		for (auto i : a.dane)
		{
			out << i << " ";
		}
		out << ")";

		return out;
	}

	friend wektor<T> operator+(wektor<T> a, wektor<T> b)
	{
		for (size_t i = 0; i < a.dane.size(); i++)
		{
			a.dane[i] += b.dane[i];
		}

		return a;
	}

	friend wektor<T> operator-(wektor<T> a, wektor<T> b)
	{
		for (size_t i = 0; i < a.dane.size(); i++)
		{
			a.dane[i] -= b.dane[i];
		}

		return a;
	}

	friend T operator*(wektor<T> a, wektor<T> b)
	{
		T tresult = 0;

		for (size_t i = 0; i < a.dane.size(); i++)
		{
			tresult += a.dane[i] * b.dane[i];
		}

		return tresult;
	}
};

