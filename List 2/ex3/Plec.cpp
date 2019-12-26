#include "Plec.hpp"

Plec::Plec(char g)
{
    gender = g;
}

bool Plec::czy_kobieta(void)
{
    if(gender == 'k')
    {
        return true;
    }

    return false;
}

char Plec::zwroc_plec(void) const
{
    return gender;
}

std::ostream& operator<<(std::ostream& wyjscie, Plec p)
{
    return wyjscie << p.zwroc_plec();
}
