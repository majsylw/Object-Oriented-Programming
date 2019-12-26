#include "Podryzyko.hpp"

#include <cassert>

Podryzyko::Podryzyko(double p)
:procent(p)
{
    assert(p>=0 && p<=1);
}

double Podryzyko::Procent(void) const
{
    return procent;
}

double Podryzyko::Skladka(double kwota)
{
    return procent*kwota;
}
