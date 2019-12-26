#include "Droga.h"

void Droga::dodaj_punkt(Punkt p)
{
    zbior_punktow.push_back(p);
}

double Droga::odcinek(const Punkt p1, const Punkt p2)
{
    double dlugosc = std::sqrt(
                               std::pow(p1.podaj_x() - p2.podaj_x(),2) +
                               std::pow(p1.podaj_y() - p2.podaj_y(),2)
                               );
    return dlugosc;
}

double Droga::dlugosc(void)
{
    assert(zbior_punktow.size() >= 2);

    double d = 0.0;

    for(unsigned int i = 0; i < (zbior_punktow.size() - 1); ++i)
    {
        d += odcinek(zbior_punktow[i], zbior_punktow[i+1]);
    }

    return d;
}
