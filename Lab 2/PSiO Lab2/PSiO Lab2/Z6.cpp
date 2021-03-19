#include <iostream>
#include <vector>

std::vector<double> bubble_sort(std::vector<double> input_vector)
{
	bool anything_changed;
	size_t size = input_vector.size();

	do
	{
		anything_changed = false;
		size_t i = 0;

		while (i < size - 1)
		{
			if (input_vector[i] > input_vector[i + 1])
			{
				anything_changed = true;
				double temp = input_vector[i];
				input_vector[i] = input_vector[i + 1];
				input_vector[i + 1] = temp;
			}
			i++;
		}

		size--;

	} while (anything_changed);

	return input_vector;
}

int main()
{
	std::vector<double> data = { 1.0, 0.9 , 0.8 , 0.7 , 0.6 , 0.5 , 0.4 , 0.3 , 0.2 , 0.1 , 0.0 };
	data = bubble_sort(data);

	for (auto i : data)
	{
		std::cout << i << std::endl;
	}

	return 0;
}