#pragma once
#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <iostream>
#include <exception>


class Data
{
    int rok;
    int miesiac;
    int dzien;

public:
    Data (int r, int m,int d);
    int podaj_rok(void) const;
    int podaj_miesiac(void) const;
    int podaj_dzien(void) const;

    class ZlaData: public virtual std::exception {
    public:
        const char* what(void) const noexcept override;
    };

    class ZlyRok: public ZlaData {
    public:
        const char* what(void) const noexcept override;
    };

    class ZlyMiesiac: public ZlaData {
    public:
        const char* what(void) const noexcept override;
    };

    class ZlaIloscDni: public ZlaData {
        int numer;
    public:
        ZlaIloscDni(int n);
        const char* what(void) const noexcept override;
    };
};

std::istream& operator>>(std::istream& wejscie, Data& d);
std::ostream& operator<<(std::ostream& wyjscie, Data d);
bool operator==(Data d, Data t);
bool operator!=(Data d, Data t);

void test_Daty(void);

#endif // DATA_HPP_INCLUDED
