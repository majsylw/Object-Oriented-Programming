#pragma once
#ifndef PUNKT_H_INCLUDED
#define PUNKT_H_INCLUDED

#include <iostream>

class Punkt
{
    double wspolrzedna_x;
    double wspolrzedna_y;

public:

    Punkt(double x = 0, double y = 0);
    double podaj_x(void) const;
    double podaj_y(void) const;
};
std::istream& operator>>(std::istream& wejscie, Punkt& d);

#endif // PUNKT_H_INCLUDED
