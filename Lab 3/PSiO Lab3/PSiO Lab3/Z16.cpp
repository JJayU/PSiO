#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void load_exchange_rates(std::string filename, std::vector<exchange_rate>& vector_to_save)
{
    std::fstream file(filename, std::fstream::in);

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
            vector_to_save.emplace_back(er);
        }
    }
}

std::ostream& operator<< (std::ostream& out, std::vector<exchange_rate>& input_vector)
{
    out << "\n  DATA       USD       EUR        TABLE_ID";
    for (auto i : input_vector)
    {
        out << "\n" << i.date << "    " << std::setw(6) << i.usd << "    " << std::setw(6) << i.eur << "    " << i.table_id;
    }

    return out;
}

void sort_usd(std::vector<exchange_rate>& input)
{
    std::sort(input.begin(), input.end(),
        [](exchange_rate& a, exchange_rate& b) { return a.usd < b.usd; });
}

void sort_eur(std::vector<exchange_rate>& input)
{
    std::sort(input.begin(), input.end(),
        [](exchange_rate& a, exchange_rate& b) { return a.eur < b.eur; });
}

//display *count* elements from top (*top_or_last* = false) or bottom (*top_or_last* = true) of the list *input*
void display_top_last(static std::vector<exchange_rate> input, bool top_or_last, size_t count)
{
    std::cout << "\n  DATA       USD       EUR        TABLE_ID";
    if (top_or_last)
    {
        for (auto i = input.begin(); i < input.begin() + count; ++i)
        {
            std::cout << "\n" << i->date << "    " << std::setw(6) << i->usd << "    " << std::setw(6) << i->eur << "    " << i->table_id;
        }
    }
    else
    {
        for (auto i = input.end() - 1; i > input.end() - count - 1; --i)
        {
            std::cout << "\n" << i->date << "    " << std::setw(6) << i->usd << "    " << std::setw(6) << i->eur << "    " << i->table_id;
        }
    }
}

int main()
{
    std::vector<exchange_rate> data;
    load_exchange_rates("kursy_usd_eur.csv", data);

    sort_eur(data);
    std::cout << "\n\n10 dni z najnizszym kursem EUR: ";
    display_top_last(data, true, 10);

    sort_usd(data);
    std::cout << "10 dni z najwyzszym kursem USD: ";
    display_top_last(data, false, 10);

    struct Comp
    {
        bool operator() (const exchange_rate& a, double b) const { return a.usd < b; };
        bool operator() (double a, const exchange_rate& b) const { return a < b.usd; };
    };

    auto wynik = std::equal_range(data.begin(), data.end(), 3.9011, Comp{});
    std::cout << "\n\nDzien z wartoscia kursu USD rowna 3.9011:\n";
    std::cout << data[wynik.first - data.begin()].date << std::endl;
    std::cout << data[wynik.first - data.begin()].usd << std::endl;
    std::cout << data[wynik.first - data.begin()].eur << std::endl;
    std::cout << data[wynik.first - data.begin()].table_id << std::endl;

	return 0;
}