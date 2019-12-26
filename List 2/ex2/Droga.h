#pragma once
#ifndef DROGA_H_INCLUDED
#define DROGA_H_INCLUDED

#include "Punkt.h"
#include <cassert>
#include <cmath>
#include <vector>

class Droga
{
    std::vector<Punkt> zbior_punktow;

public:

    void dodaj_punkt(Punkt p);
    double odcinek(const Punkt p1, const Punkt p2);
    double dlugosc(void);
};

#endif // DROGA_H_INCLUDED
