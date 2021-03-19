#include <iostream>
#include <vector>

int binary_search(std::vector<double> input_vector, double to_find)
{
	size_t length = input_vector.size();
	size_t actual_beginning = 0;
	size_t actual_end = length;

	while (length > 1)
	{
		int middle_point = (actual_beginning + actual_end) / 2;

		if (input_vector[middle_point] == to_find)
		{
			return middle_point;
		}
		else if (input_vector[middle_point] > to_find)
		{
			actual_end = middle_point;
		}
		else if (actual_end - actual_beginning == 1)
		{
			break;
		}
		else
		{
			actual_beginning = middle_point;
		}
	}

	if (input_vector[0] == to_find)
	{
		return actual_beginning;
	}
	else
	{
		return -1;
	}
}

int main()
{
	std::vector<double> data = { 0,1,2,3,4,5,6,7,8,9 };
	
	std::cout << binary_search(data, 7);

	return 0;
}