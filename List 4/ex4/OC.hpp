#ifndef OC_HPP_INCLUDED
#define OC_HPP_INCLUDED

#include "Podryzyko.hpp"
#include <cassert>

class OC: public Podryzyko
{
    double kwota_gwarancyjna;

public:
    OC(double kurs);
    double Skladka(double rabat = 0.0);
};

#endif // OC_HPP_INCLUDED
