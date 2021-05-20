#pragma once

#include <iostream>

//int, float, double
template <typename T>
class complexnumber
{
private:
	T real;
	T im;
public:
	complexnumber()
	{
		real = 0;
		im = 0;
	}

	complexnumber(T a, T b)
	{
		real = a;
		im = b;
	}

	friend complexnumber operator+(complexnumber<T> a, complexnumber<T> b)
	{
		a.real = a.real + b.real;
		a.im = a.im + b.im;

		return a;
	}

	friend std::ostream& operator<<(std::ostream& out, complexnumber<T>& a)
	{
		out << a.real << " + " << a.im << "i";
		return out;
	}

	friend complexnumber operator*(complexnumber<T> a, complexnumber<T> b)
	{
		complexnumber<T> c;

		c.real = a.real * b.real - a.im * b.im;
		c.im = a.real * b.im + b.real * a.im;

		return c;
	}
};


