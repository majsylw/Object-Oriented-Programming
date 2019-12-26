#include "Punkt.h"

Punkt::Punkt(double x, double y)
{
    wspolrzedna_x = x;
    wspolrzedna_y = y;
}

double Punkt::podaj_x(void) const
{
    return wspolrzedna_x;
}

double Punkt::podaj_y(void) const
{
    return wspolrzedna_y;
}

std::istream& operator>>(std::istream& wejscie, Punkt& d)
{
    double x = 0.0;
    double y = 0.0;

    wejscie >> x >> y;

    if(wejscie)
    {
        d = Punkt(x,y);
    }

    return wejscie;
}
