#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct measured_data
{
	std::string date;
	std::string time;
	double sound_speed;
	double sound_temp;
	double atm_pressure;
	double temperature;
	double humidity;
	double compass;
	double uv_speed;
	double wind_speed;
	double wind_dir;
	double height;
	double inside_temp;
};

std::vector<measured_data> load_measured_data(std::string filename)
{
    std::fstream file(filename, std::fstream::in);
    std::vector<measured_data> temp_data;

    if (file.is_open())
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream str(line);

            measured_data er;
            std::getline(str, er.date, ',');
            std::getline(str, er.time, ',');
            std::string double_str;
            std::getline(str, double_str, ',');
            er.sound_speed = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.sound_temp = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.atm_pressure = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.temperature = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.humidity = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.compass = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.uv_speed = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.wind_speed = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.wind_dir = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.height = std::stod(double_str);
            std::getline(str, double_str, ',');
            er.inside_temp = std::stod(double_str);

            temp_data.emplace_back(er);
        }
    }

    return temp_data;
}

std::vector<measured_data> bubble_sort(std::vector<measured_data> input_vector)
{
    bool anything_changed;
    size_t size = input_vector.size();

    do
    {
        anything_changed = false;
        size_t i = 0;

        while (i < size - 1)
        {
            if (input_vector[i].temperature > input_vector[i + 1].temperature)
            {
                anything_changed = true;
                double temp = input_vector[i].temperature;
                input_vector[i] = input_vector[i + 1];
                input_vector[i + 1].temperature = temp;
            }
            i++;
        }

        size--;

    } while (anything_changed);

    return input_vector;
}

int main()
{
    std::vector<measured_data> data = bubble_sort(load_measured_data("temp02-2020.csv"));

    for (size_t i = 0; i < data.size(); i++)
    {
        if (i == 0)
        {
            std::cout << "Temperatura minimalna: " << data[i].temperature << std::endl;
        }
        if (i == data.size() - 1)
        {
            std::cout << "Temperatura maksymalna: " << data[i].temperature << std::endl;
        }
        if (i == data.size() / 2)
        {
            std::cout << "Mediana temperatur: " << data[i].temperature << std::endl;
        }
    }

	return 0;
}