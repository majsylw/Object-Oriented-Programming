#include "Karta.hpp"

#include<cctype>
#include<cassert>
#include<cstring>
#include<iostream>

bool algorytm_luhna(std::string n)
{
    int suma = 0;
    bool nieparzyste = false;

    for(int i = n.size() - 1; i >= 0; --i)
    {
        int pomocnicza = n[i] - '0';
        if(nieparzyste)
        {
            pomocnicza *= 2;
            if(pomocnicza > 9)
            {
                pomocnicza -= 9;
            }
        }
        suma += pomocnicza;
        nieparzyste = (!nieparzyste);
    }
    return (suma%10 == 0);
}

Karta::ZlyNumer::ZlyNumer(std::string w)
{
    strncpy(wrong,w.c_str(),sizeof(wrong) - 1);
}
const char* Karta::ZlyNumer::what() const noexcept { return wrong; }

Karta::ZlaSuma::ZlaSuma(std::string b):
    ZlyNumer(b)
{
    strncpy(blad,b.c_str(),sizeof(blad) - 1);
}
const char* Karta::ZlaSuma::what() const noexcept { return blad; }

Karta::Karta(std::string nr)
{
    if(nr.empty()) throw ZlyNumer("Brak napisu!");

    for(unsigned int i = 0; i < nr.size(); ++i)
    {
            if(isspace(nr[i]))
            {
                nr.erase(nr.begin() + i);
            }
            else
            {
                if(!isdigit(nr[i]))
                    throw ZlyNumer("Wpisujesz nie tylko cyfry i spacje!");
            }
    }

    if(nr.size() != 16) throw ZlyNumer("Podano za duzo cyfr!");

    if(!algorytm_luhna(nr)) throw ZlaSuma("Numer nie przeszedl testu sumy.");

    numer = nr;
}

std::string Karta::ZwrocNumer(void) const
{
    return numer;
}

void test_Karty(void)
{
    bool blad = false;
    try
    {
        Karta k("4779 1539 2488 0170");
    }
    catch(Karta::ZlyNumer& e)
    {
        blad = true;
    }
    assert(blad == false);

    try
    {
        Karta k1("");
    }
    catch(Karta::ZlyNumer& e)
    {
        assert( strcmp( e.what(), "Brak napisu!" ) == 0 );
    }

    try
    {
        Karta k2("4/79 15s9 24A8 0170");
    }
    catch(Karta::ZlyNumer& e)
    {
        assert( strcmp( e.what(), "Wpisujesz nie tylko cyfry i spacje!" ) == 0 );
    }

    try
    {
        Karta k3("4779 1539 2488 01789 87870");
    }
    catch(Karta::ZlyNumer& e)
    {
        assert( strcmp( e.what(), "Podano za duzo cyfr!") == 0 );
    }

    try
    {
        Karta k4("4779 1539 2488 0172");
    }
    catch(Karta::ZlyNumer& e)
    {
        assert( strcmp( e.what(), "Numer nie przeszedl testu sumy." ) == 0 );
    }

    std::cerr << "Klasa Karta pomyslnie przeszla testy." << std::endl;
}
