#include "Data.hpp"

#include <sstream>
#include <cassert>
#include <cstring>
#include <limits>

const char* Data::ZlaData::what(void) const noexcept { return "Podales zla date, nie objeta kalendarzem gregorianskim."; }

const char* Data::ZlyRok::what(void) const noexcept { return "Podales zly rok, nie objety kalendarzem gregorianskim."; }

const char* Data::ZlyMiesiac::what() const noexcept { return "Podales zly miesiac. Numer miesiaca powinien byc z zakresu [1,12]."; }

Data::ZlaIloscDni::ZlaIloscDni(int n) : numer(n) {}

const char* Data::ZlaIloscDni::what() const noexcept {
    assert(numer <= 4);
    if (numer == 1)
        return "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,31].";
    if (numer == 2)
        return "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,30].";
    if(numer == 3)
        return "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,29].";
    else
        return "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,28].";
}

Data::Data (int r,int m,int d)
{
    if(r < 1582) throw ZlyRok();
    if(m < 1 || m > 12) throw ZlyMiesiac();
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d < 1 || d > 31)
                throw ZlaIloscDni(1);
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if(d < 1 || d > 30)
                throw ZlaIloscDni(2);
    }
    if (m == 2)
    {
            if ((r%4 == 0 && r%100 != 0) || r%400 == 0)
            {
                if(d < 1 || d > 29)
                    throw ZlaIloscDni(3);
            }
            else
            {
                if(d < 1 || d > 28)
                    throw ZlaIloscDni(4);
            }
    }

    rok = r;
    miesiac = m;
    dzien = d;
}

int Data::podaj_rok(void) const
{
    return rok;
}

int Data::podaj_miesiac(void) const
{
    return miesiac;
}

int Data::podaj_dzien(void) const
{
    return dzien;
}

std::istream& operator>>(std::istream& wejscie, Data& d)
{
    int ro = 0;
    int mi = 0;
    int dz = 0;

    wejscie.exceptions ( std::istream::failbit | std::istream::badbit );
    while(true)
    {
        try
        {
            wejscie >> ro >> mi >> dz;
            d = Data(ro,mi,dz);
            break;
        }
        catch(std::ios_base::failure& e)
        {
            std::cout << "Wpisano zle dane! \n" << std::endl;
            wejscie.clear();
            wejscie.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch(Data::ZlyRok& er)
        {
            std::cout << er.what() << std::endl;
        }
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Data d)
{
    return wyjscie << d.podaj_rok() << "." << d.podaj_miesiac() << "." << d.podaj_dzien();
}

bool operator==(Data d, Data t)
{
	return (t.podaj_dzien() == d.podaj_dzien() && t.podaj_miesiac() == d.podaj_miesiac() && t.podaj_rok() == d.podaj_rok());
}

bool operator!=(Data d, Data t)
{
	return !( d == t );
}

void test_Daty(void)
{
    Data d(2014,10,19);

    std::ostringstream data;
    data.str("");
    data << d;
    assert(data.str() == "2014.10.19");
    data.str("");

    std::istringstream data2;
    data2.str("2014 11 19");
    Data d2(1999,10,11);
    data2 >> d2;
    assert(data2);

    try
    {
        Data p1(1,6,1);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Podales zly rok, nie objety kalendarzem gregorianskim." ) == 0 );
    }

    try
    {
        Data p1(1992,15,1);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Podales zly miesiac. Numer miesiaca powinien byc z zakresu [1,12]." ) == 0 );
    }

    try
    {
        Data p1(1992,1,32);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,31]." ) == 0 );
    }

    try
    {
        Data p1(1992,4,31);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,30]." ) == 0 );
    }

    try
    {
        Data p1(1992,2,30);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,29]." ) == 0 );
    }

    try
    {
        Data p1(1993,2,29);
    }
    catch(Data::ZlyRok& e)
    {
        assert( strcmp( e.what(), "Wprowadzony miesiac nie moze posiadac takiej ilosci dni. Liczba dni powinna byc z zakresu [1,28]." ) == 0 );
    }
}

