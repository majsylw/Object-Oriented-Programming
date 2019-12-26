#pragma once
#ifndef PLEC_HPP_INCLUDED
#define PLEC_HPP_INCLUDED

#include <iostream>

class Plec
{
    char gender;

public:
    Plec(char g);
    bool czy_kobieta(void);
    char zwroc_plec(void) const;

    class ZlaPlec: public virtual std::exception {
        public:
            const char* what(void) const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& wyjscie, Plec p);

#endif // PLEC_HPP_INCLUDED
