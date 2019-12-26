#pragma once
#ifndef WYMIERNA_HPP_INCLUDED
#define WYMIERNA_HPP_INCLUDED

class Wymierna
{
    long licznik;
    long mianownik;

public:
    Wymierna(long l, long m);
    inline long Licznik(void) const {return licznik;};
    inline long Mianownik(void) const {return mianownik;};
};

auto test_Wymierna(void) -> void;


#endif // WYMIERNA_HPP_INCLUDED
