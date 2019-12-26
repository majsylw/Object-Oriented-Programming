#include "Dzialalnosc_gospodarcza.hpp"

Podatnik::Podatnik(std::string nip)
:nip_(nip) {}

Podatnik::~Podatnik(void) = default;

std::string Podatnik::Nip(void) const
{
    return nip_;
}

Osoba::Osoba(std::string i, std::string n)
:imie(i), nazwisko(n) {}

std::string Osoba::Imie(void) const
{
    return imie;
}

std::string Osoba::Nazwisko(void) const
{
    return nazwisko;
}

OsobaFizyczna::OsobaFizyczna(std::string nip, std::string i, std::string n)
:Podatnik(nip), Osoba(i,n) {}

void OsobaFizyczna::wizytowka(void) const
{
    std::cout << "Dane osobowe: " << Imie() << " " << Nazwisko() << '\n'
              << "NIP: " << Nip();
}

Dzialalnosc::Dzialalnosc(std::string nip, std::string r)
:Podatnik(nip), regon(r) {}

std::string Dzialalnosc::Regon(void) const
{
    return regon;
}

void Dzialalnosc::wizytowka(void) const
{
    std::cout << "NIP: " << Nip() << '\n'
              << "REGON: " << Regon() << '\n';
}

Firma::Firma(std::string nazw, std::string nip, std::string regon)
:Dzialalnosc(nip, regon), nazwa(nazw) {}

std::string Firma::Nazwa() const
{
    return nazwa;
}

void Firma::wizytowka(void) const
{
    std::cout << "Nazwa firmy: " << Nazwa() << '\n'
              << "NIP: " << Nip() << '\n'
              << "REGON: " << Regon() << '\n';
}

IndywidualnaDzialalnosc::IndywidualnaDzialalnosc(std::string nip, std::string imie, std::string nazwisko, std::string regon)
:Osoba(imie, nazwisko), Dzialalnosc(nip, regon){}

void IndywidualnaDzialalnosc::wizytowka(void) const
{
    std::cout << "Dane osobowe: " << Imie() << " " << Nazwisko() << '\n'
              << "NIP: " << Nip() << '\n'
              << "REGON: " << Regon() << '\n';
}

