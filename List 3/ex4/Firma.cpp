#include "Firma.hpp"

Firma::Firma(std::string n, std::string np)
: nazwa(n), nip(np)
{}

std::string Firma::Dane(void)
{
    return "<firma " + nazwa + " " + nip + ">";
}
