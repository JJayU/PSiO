#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct exchange_rate
{
	std::string date;
	double usd;
	double eur;
	std::string table_id;
};

std::vector<exchange_rate> load_exchange_rates(std::string filename)
{
	std::fstream file(filename, std::fstream::in);
    std::vector<exchange_rate> temp_rates;

    if (file.is_open()) 
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) 
        {
            std::stringstream str(line);

            exchange_rate er;
            std::getline(str, er.date, ',');
            std::string double_str;
            std::getline(str, double_str, ',');
            er.usd = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.eur = std::stod(double_str);
            std::getline(str, er.table_id, ',');
            temp_rates.emplace_back(er);
        }
    }

    return temp_rates;
}

std::vector<exchange_rate> sort_usd(std::vector<exchange_rate> input_vector)
{
	bool anything_changed;
	size_t size = input_vector.size();

	do
	{
		anything_changed = false;
		size_t i = 0;

		while (i < size - 1)
		{
			if (input_vector[i].usd > input_vector[i + 1].usd)
			{
				anything_changed = true;
				double temp = input_vector[i].usd;
				input_vector[i] = input_vector[i + 1];
				input_vector[i + 1].usd = temp;
			}
			i++;
		}

		size--;

	} while (anything_changed);

	return input_vector;
}

std::vector<exchange_rate> sort_eur(std::vector<exchange_rate> input_vector)
{
	bool anything_changed;
	size_t size = input_vector.size();

	do
	{
		anything_changed = false;
		size_t i = 0;

		while (i < size - 1)
		{
			if (input_vector[i].eur > input_vector[i + 1].eur)
			{
				anything_changed = true;
				double temp = input_vector[i].eur;
				input_vector[i] = input_vector[i + 1];
				input_vector[i + 1].eur = temp;
			}
			i++;
		}

		size--;

	} while (anything_changed);

	return input_vector;
}

int binary_search_usd(std::vector<exchange_rate> input_vector, double to_find)
{
	size_t length = input_vector.size();
	size_t actual_beginning = 0;
	size_t actual_end = length;

	while (length > 1)
	{
		int middle_point = (actual_beginning + actual_end) / 2;

		if (input_vector[middle_point].usd == to_find)
		{
			return middle_point;
		}
		else if (input_vector[middle_point].usd > to_find)
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

	if (input_vector[0].usd == to_find)
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
	std::vector<exchange_rate> rates;
	rates = load_exchange_rates("kursy_usd_eur.csv");

	rates = sort_usd(rates);

	std::cout << "10 dni z najwyszym kursem USD:\n";
	for (int i = rates.size() - 10; i < rates.size(); i++)
	{
		std::cout << rates[i].date << "  " << rates[i].usd << std::endl;
	}

	rates = sort_eur(rates);

	std::cout << "\n\n10 dni z najnizszym kursem EUR:\n";
	for (int i = 10; i >= 0; i--)
	{
		std::cout << rates[i].date << "  " << rates[i].eur << std::endl;
	}

	std::cout << "\n\nKurs USD wynosil 3.9011PLN dnia: " << rates[binary_search_usd(rates, 3.9011)].date << std::endl;

	return 0;
}