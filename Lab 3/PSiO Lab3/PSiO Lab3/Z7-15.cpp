#include <iostream>
#include <vector>
#include <string>

enum class TypRosliny
{
	Owoc,
	Warzywo
};

struct Roslina
{
	TypRosliny typ;
	std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<< (std::ostream& out, const Roslina& roslina)
{
	out << "Typ: " << ( int(roslina.typ) ? "Warzywo" : "Owoc" ) << "\nNazwa: " << roslina.nazwa << std::endl;
	return out;
}

std::ostream& operator<< (std::ostream& out, const Koszyk koszyk)
{
	out << "\nZawartosc koszyka:\n\n";

	for (size_t i = 0; i < koszyk.size(); i++)
	{
		if (i > 0)
		{
			out << "---\n";
		}
		out << koszyk[i];
	}

	return out;
}

bool czy_jest_gruszka(const Koszyk& koszyk)
{
	return std::end(koszyk) != std::find_if(koszyk.begin(), koszyk.end(),
		[](Roslina a) {return a.nazwa == "Gruszka"; });
}

int main()
{
	Koszyk koszyk;

	koszyk.push_back(Roslina{ TypRosliny::Owoc, "Jablko" });
	//koszyk.push_back({ TypRosliny::Owoc, "Gruszka" });
	koszyk.push_back(Roslina());
	koszyk[koszyk.size() - 1].typ = TypRosliny::Warzywo;
	koszyk[koszyk.size() - 1].nazwa = "Marchewka";
	Roslina Pomidor = { TypRosliny::Owoc, "Pomidor" };
	koszyk.push_back(Pomidor);

	std::cout << koszyk;

	if (czy_jest_gruszka(koszyk))
	{
		std::cout << "\nW koszyku jest gruszka!\n";
	}
	else
	{
		std::cout << "\nW koszyku nie ma gruszki!\n";
	}

	return 0;
}