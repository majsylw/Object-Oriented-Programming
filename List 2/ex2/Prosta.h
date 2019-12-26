#pragma once
#ifndef PROSTA_H_INCLUDED
#define PROSTA_H_INCLUDED

#include "Punkt.h"
#include <cassert>

class Prosta
{
    Punkt p1_;
    Punkt p2_;

public:

    Prosta(Punkt p1, Punkt p2);
    double wspolczynnik_kierunkowy_prostej(void);
    double wspolczynnik_przesuniecia_prostej(void);
};

#endif // PROSTA_H_INCLUDED
