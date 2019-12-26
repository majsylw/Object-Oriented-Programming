#include "Data.hpp"

bool przestepny(int rok)
{
    return ((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool poprawna_data(int dzien, int miesiac, int rok)
{
    if(rok > 1899)
    {
        if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12)
        {
            if (dzien > 0 && dzien < 32)
                return true;
        }
        else
        {
            if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
            {
                if(dzien > 0 && dzien < 31)
                    return true;
            }
            if (miesiac == 2)
            {
                if (przestepny(rok))
                {
                    if(dzien > 0 && dzien < 30)
                        return true;
                }
                else
                {
                    if(dzien > 0 && dzien < 29)
                        return true;
                }
            }
        }
    }

    return false;
}

Data::Data (void)
{
    rok = 1582;
    miesiac = 1;
    dzien = 1;
}

Data::Data (int r, int m,int d)
{
    assert(poprawna_data(d,m,r));
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

    wejscie >> ro >> mi >> dz;

    if(wejscie)
    {
        if(poprawna_data(dz,mi,ro))
            d = Data(ro,mi,dz);
        else
            wejscie.setstate(std::ios_base::failbit);
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
