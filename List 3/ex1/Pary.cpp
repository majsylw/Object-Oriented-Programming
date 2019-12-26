#include "Pary.hpp"

#include <iostream>
#include <cassert>
#include <cstring>

double Pary::zwroc (std::string napis) const
{
    assert(napisy.size() == liczby.size());

    unsigned int i=0;
    for(i=0; i < napisy.size(); ++i)
    {
        if(napisy[i] == napis)
            break;
    }

    if(i < napisy.size()){return liczby[i];}
    else {throw BrakKlucza{};}
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

void test_pary(void)
{
    Pary d;
    d.dodaj_pare("Dwa",2);
    d.dodaj_pare("Trzy", 3);
    d.dodaj_pare("Jeden", 1);
    assert(d.zwroc("Dwa") == 2);
    d.dodaj_pare("Dwa", 0);
    assert(d.zwroc("Dwa") == 0);

    bool error = false;

    try
    {
        d.zwroc("Trzy");
    }
    catch(BrakKlucza& e)
    {
        error = true;
    }

    assert(error == false);

    try
    {
        d.zwroc("Cztery");
    }
    catch(BrakKlucza& e)
    {
        error = true;
    }

    assert(error == true);

    std::cerr << "Test_Pary przeszedl pomyslnie." << std::endl;
}
