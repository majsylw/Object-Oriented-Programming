#include "Wypadek.hpp"

Wypadek::Wypadek(int wiek, double udzial)
:Podryzyko(0.0), udzial_wlasny(udzial)
{
    if (wiek < 26)
    {
        procent = 0.2;
    }
    else
    {
        procent = 0.1;
    }
}
double Wypadek::Skladka(double kwota)
{
    return procent*(kwota - udzial_wlasny);
}
