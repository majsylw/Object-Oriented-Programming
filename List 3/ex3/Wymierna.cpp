#include "Wymierna.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

Wymierna::Wymierna(long l = 0, long m = 1)
{
    assert(m != 0);

    int najm = 0;
    int znak = 1;

    if(l < 0 || m < 0)
    {
        l = std::abs(l);
        m = std::abs(m);
        znak = -1;
    }

    if(m >= l)
        najm = l;
    else
        najm = m;

    for(int i = najm; i >= 1; --i)
    {
        if(l%i == 0 && m%i == 0)
        {
            l /= i;
            m /= i;
        }
    }

    licznik = l * znak;
    mianownik = m;
}

auto test_Wymierna(void) -> void
{
    Wymierna w1(2,-4);
    assert(w1.Licznik()==-1);
    assert(w1.Mianownik()==2);

    Wymierna w2;
    assert(w2.Licznik()==0);
    assert(w2.Mianownik()==1);

    Wymierna w3(2);
    assert(w3.Licznik()==2);
    assert(w3.Mianownik()==1);

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}
