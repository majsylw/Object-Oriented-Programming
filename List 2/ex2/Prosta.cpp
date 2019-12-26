#include "Prosta.h"

Prosta::Prosta(Punkt p1, Punkt p2)
{
    p1_ = p1;
    p2_ = p2;
}

double Prosta::wspolczynnik_kierunkowy_prostej(void)
{
    assert(p1_.podaj_x() != p2_.podaj_x() && p1_.podaj_y() != p2_.podaj_y());

    assert(p2_.podaj_x() - p1_.podaj_x() != 0);

    double a = (p2_.podaj_y() - p1_.podaj_y())/(p2_.podaj_x() - p1_.podaj_x());
    return a;
}

double Prosta::wspolczynnik_przesuniecia_prostej(void)
{
    assert(p1_.podaj_x() != p2_.podaj_x() && p1_.podaj_y() != p2_.podaj_y());

    assert(p2_.podaj_x() - p1_.podaj_x() != 0);

    double b = p1_.podaj_y() - ((p2_.podaj_y() - p1_.podaj_y())*p1_.podaj_x())/(p2_.podaj_x() - p1_.podaj_x());
    return b;
}

