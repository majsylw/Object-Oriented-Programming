#ifndef Osoba_HPP_INCLUDED
#define Osoba_HPP_INCLUDED

#include "Data.hpp"
#include "Pesel.hpp"
#include "Plec.hpp"

#include <string>

class Osoba
{
    private:
        std::string imie;
        std::string nazwisko;
        Plec plec;
        Pesel pesel;
        Data data_urodzenia;

    public:
        Osoba(std::string i, std::string n, std::string p, char pl, int r, int m, int d);
        std::string Dane(void);

        class BrakSpojnosci: public Data::ZlaData, public Pesel::ZlyPesel, public Plec::ZlaPlec {
            public:
                const char* what(void) const noexcept override;
        };

        class NiespojnaData: public BrakSpojnosci {
            public:
                const char* what(void) const noexcept override;
        };

        class NiespojnaPlec: public BrakSpojnosci {
            public:
                const char* what(void) const noexcept override;
        };
};

#endif // Osoba_HPP_INCLUDED
