#pragma once
#ifndef PARY_HPP_INCLUDED
#define PARY_HPP_INCLUDED

#include <vector>
#include <string>


class BrakKlucza : public std::exception {};

class Pary
{
    std::vector<std::string> napisy;
    std::vector<double> liczby;

public:

    double zwroc (std::string napis) const;
    void dodaj_pare (std::string napis, double liczba);
    void wypisz_pary(void);

};

void test_pary(void);

#endif // PARY_HPP_INCLUDED
