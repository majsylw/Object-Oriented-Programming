#pragma once
#ifndef PESEL_HPP_INCLUDED
#define PESEL_HPP_INCLUDED

#include "Data.hpp"
#include <cstdlib>
#include <sstream>
#include <cassert>


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

    class ZlyPesel: public virtual std::exception {
        public:
            const char* what(void) const noexcept override;
    };

    class ZlaDataWPesel: public ZlyPesel {
        public:
            const char* what(void) const noexcept override;
    };

    class ZlaCyfraKontrolna: public ZlyPesel {
        public:
            const char* what(void) const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& wyjscie, Pesel p);
std::istream& operator>>(std::istream& wejscie, Pesel& p);

#endif // PESEL_HPP_INCLUDED
