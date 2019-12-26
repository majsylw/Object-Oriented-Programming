#include "Pary.hpp"

double Pary::zwroc (std::string napis) const
{
    assert(napisy.size() == liczby.size());

    unsigned int i=0;
    for(i=0; i < napisy.size(); ++i)
    {
        if(napisy[i] == napis)
            break;
    }

    assert(i < napisy.size());

    return liczby[i];
}

void Pary::dodaj_pare (std::string napis, double liczba)
{
    assert(napisy.size() == liczby.size());

    unsigned int i=0;
    for(i=0; i < napisy.size(); ++i)
    {
        if(napisy[i] == napis)
            break;
    }

    if(i == napisy.size())
    {
        napisy.push_back(napis);
        liczby.push_back(liczba);
    }
    else
    {
        liczby[i] = liczba;
    }

}

void Pary::wypisz_pary(void)
{
    assert(napisy.size() == liczby.size());

    for(unsigned int i=0; i < napisy.size(); ++i)
    {
        std::cout << napisy[i] << '\t' << liczby[i] << '\n';
    }
}
