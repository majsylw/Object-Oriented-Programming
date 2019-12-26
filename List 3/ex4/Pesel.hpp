#pragma once
#ifndef PESEL_HPP_INCLUDED
#define PESEL_HPP_INCLUDED

#include "Data.hpp"
#include <cstdlib>
#include <sstream>
#include <cassert>

bool poprawna_data_w_PESEL(std::string pesel);
bool poprawna_cyfra_kontrolna(std::string pesel);


class Pesel
{
    std::string nr_pesel;

public:
    Pesel(std::string pesel);
    Pesel(void);
    std::string Numer(void) const;
    Data Data_ur(void);
    bool czy_kobieta(void);

    bool CzyPoprawny(void);

};

std::ostream& operator<<(std::ostream& wyjscie, Pesel p);
std::istream& operator>>(std::istream& wejscie, Pesel& p);

#endif // PESEL_HPP_INCLUDED
