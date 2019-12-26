#ifndef WYPADEK_HPP_INCLUDED
#define WYPADEK_HPP_INCLUDED

#include "Podryzyko.hpp"

class Wypadek: public Podryzyko
{
    double udzial_wlasny;

public:
    explicit Wypadek(int wiek, double udzial);
    double Skladka(double kwota);
};

#endif // WYPADEK_HPP_INCLUDED
