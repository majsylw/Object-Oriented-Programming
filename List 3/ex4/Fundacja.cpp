#include "Fundacja.hpp"

Fundacja::Fundacja(std::string n, std::string k, bool p)
: nazwa(n), krs(k), opp(p)
{}

std::string Fundacja::Dane(void)
{
    std::string napis = "<fundacja " + nazwa + " " + krs + " ";
    if(opp)
    {
        napis += "1>";
    }
    else
        napis += "0>";

    return napis;
}
