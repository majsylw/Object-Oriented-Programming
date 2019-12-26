#ifndef OSOBAFIZYCZNA_HPP_INCLUDED
#define OSOBAFIZYCZNA_HPP_INCLUDED

#include "Data.hpp"
#include "Pesel.hpp"
#include "Podatnik.hpp"

#include <string>

class OsobaFizyczna : public Podatnik
{
    private:
        std::string imie;
        std::string nazwisko;
        Pesel pesel;
        Data data_urodzenia;

    public:
        OsobaFizyczna(std::string i, std::string n, std::string p, int r, int m, int d);
        std::string Dane(void);
};

#endif // OSOBAFIZYCZNA_HPP_INCLUDED
