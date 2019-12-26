#ifndef FUNDACJA_HPP_INCLUDED
#define FUNDACJA_HPP_INCLUDED

#include <string>
#include "Podatnik.hpp"

class Fundacja : public Podatnik
{
    private:
        std::string nazwa;
        std::string krs;
        bool opp;

    public:
        Fundacja(std::string n, std::string k, bool p);
        std::string Dane(void);
};

#endif // FUNDACJA_HPP_INCLUDED
