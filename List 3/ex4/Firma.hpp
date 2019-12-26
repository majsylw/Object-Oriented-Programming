#ifndef FIRMA_HPP_INCLUDED
#define FIRMA_HPP_INCLUDED

#include <string>
#include "Podatnik.hpp"

class Firma : public Podatnik
{
    private:
        std::string nazwa;
        std::string nip;

    public:
        Firma(std::string n, std::string np);
        std::string Dane(void);
};

#endif // FIRMA_HPP_INCLUDED
