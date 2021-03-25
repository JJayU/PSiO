#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
		[](const Roslina& a) {return a.nazwa == "Gruszka"; });
}

bool czy_same_owoce(const Koszyk& koszyk) 
{
	return std::all_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; });
}

bool czy_same_warzywa(const Koszyk& koszyk)
{
	return std::all_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; });
}

bool czy_jakis_owoc(const Koszyk& koszyk)
{
	return std::any_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; });
}

bool czy_jakies_warzywo(const Koszyk& koszyk)
{
	return std::any_of(koszyk.begin(), koszyk.end(),
		[](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; });
}

int zlicz_owoce(const Koszyk& koszyk)
{
	return std::count_if(koszyk.begin(), koszyk.end(),
		[](const Roslina& a) {return a.typ == TypRosliny::Owoc; });
}

int zlicz_warzywa(const Koszyk& koszyk)
{
	return std::count_if(koszyk.begin(), koszyk.end(),
		[](const Roslina& a) {return a.typ == TypRosliny::Warzywo; });
}

void usun_zaczynajace_sie_od(Koszyk &koszyk, char litera)
{
	koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(),
		[ litera ](const Roslina& a) { return a.nazwa[0] == litera; }));
}

int main()
{
	Koszyk koszyk;

	koszyk.push_back(Roslina{ TypRosliny::Owoc, "Jablko" });
	koszyk.push_back({ TypRosliny::Owoc, "Gruszka" });
	koszyk.push_back(Roslina());
	koszyk[koszyk.size() - 1].typ = TypRosliny::Warzywo;
	koszyk[koszyk.size() - 1].nazwa = "Marchewka";
	Roslina Kiwi = { TypRosliny::Owoc, "Kiwi" };
	koszyk.push_back(Kiwi);

	std::cout << koszyk;

	if (czy_jest_gruszka(koszyk))
	{
		std::cout << "\nW koszyku jest gruszka!\n";
	}
	else
	{
		std::cout << "\nW koszyku nie ma gruszki!\n";
	}

	if (czy_same_owoce(koszyk))
	{
		std::cout << "\nW koszyku sa same owoce\n";
	}
	else
	{
		std::cout << "\nW koszyku sa owoce i warzywa\n";
	}

	std::cout << "\nLiczba owocow: " << zlicz_owoce(koszyk);
	std::cout << "\nLiczba warzyw: " << zlicz_warzywa(koszyk) << std::endl;

	std::cout << "\nZjadam wszystkie owoce na litere G :)";
	usun_zaczynajace_sie_od(koszyk, 'G');

	std::cout << koszyk;

	//Z13 - Z15...

	return 0;
}