#ifndef RYZYKO_HPP_INCLUDED
#define RYZYKO_HPP_INCLUDED

#include "Podryzyko.hpp"
#include <vector>
#include <memory>
#include <string>

class Ryzyko
{
private:
    double cena;
    int wiek;
    double udzial;
    double rabat;
    std::string marka;
    double polisa;
    //std::vector<Podryzyko*> podryzyka;
    std::vector<std::unique_ptr<Podryzyko>> podryzyka;
    std::vector<std::string> typy;

public:
    Ryzyko(double c, int w, double u, double r, std::string m);
    void DodajPodryzyko(std::string nazwa);
    void UsunPodryzyko(std::string nazwa);
    double WartoscPojazdu(void) const;
    int WiekWlasciciela(void) const;
    std::string Marka(void) const;
    double Polisa(void) const;
    void WypiszUbezpieczenia(void) const;
};

#endif // RYZYKO_HPP_INCLUDED
