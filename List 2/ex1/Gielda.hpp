#pragma once
#ifndef GIELDA_HPP_INCLUDED
#define GIELDA_HPP_INCLUDED

#include "Pary.hpp"
#include <string>


class Gielda
{
    std::string nazwa;
    Pary kursy;
public:

    Gielda(std::string n, Pary k);
    std::string podaj_nazwe_gieldy(void) const;
    Pary wszystkie_kursy(void) const;
};

#endif // GIELDA_HPP_INCLUDED
