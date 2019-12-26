#pragma once
#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <iostream>
#include <cassert>

bool przestepny(int rok);

bool poprawna_data(int dzien, int miesiac, int rok);

class Data
{
    int rok;
    int miesiac;
    int dzien;

public:

    Data (void);
    Data (int r, int m,int d);
    int podaj_rok(void) const;
    int podaj_miesiac(void) const;
    int podaj_dzien(void) const;
};

std::istream& operator>>(std::istream& wejscie, Data& d);
std::ostream& operator<<(std::ostream& wyjscie, Data d);
bool operator==(Data d, Data t);

#endif // DATA_HPP_INCLUDED
