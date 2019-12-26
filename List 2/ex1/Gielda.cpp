#include "Gielda.hpp"

Gielda::Gielda(std::string n, Pary k)
{
    n = nazwa;
    k = kursy;
}

std::string Gielda::podaj_nazwe_gieldy(void) const
{
    return nazwa;
}

Pary Gielda::wszystkie_kursy(void) const
{
    return kursy;
}
