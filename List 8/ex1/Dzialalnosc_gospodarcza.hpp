#ifndef DZIALALNOSC_GOSPODARCZA_HPP_INCLUDED
#define DZIALALNOSC_GOSPODARCZA_HPP_INCLUDED

#include <iostream>
#include <string>

class Podatnik
{
private:
    std::string nip_;

public:
    Podatnik(std::string nip);
    virtual ~Podatnik(void);
    std::string Nip(void) const;
    virtual void wizytowka(void) const = 0;
};

class Osoba
{
private:
    std::string imie;
    std::string nazwisko;

public:
    Osoba(std::string i, std::string n);
    std::string Imie(void) const;
    std::string Nazwisko(void) const;
};

class OsobaFizyczna : public Podatnik, public Osoba
{
public:
    OsobaFizyczna(std::string nip, std::string i, std::string n);
    void wizytowka(void) const override;
};

class Dzialalnosc: public Podatnik
{
private:
    std::string regon;

public:
    Dzialalnosc(std::string nip, std::string r);
    std::string Regon(void) const;
    void wizytowka(void) const override;
};

class Firma: public Dzialalnosc
{
    std::string nazwa;
  public:
    Firma(std::string nazw, std::string nip, std::string regon);
    std::string Nazwa() const;
    void wizytowka(void) const override;
};


class IndywidualnaDzialalnosc: public Osoba, public Dzialalnosc
{
  public:
    IndywidualnaDzialalnosc(std::string nip, std::string imie, std::string nazwisko, std::string regon);
    void wizytowka(void) const override;
};

#endif // DZIALALNOSC_GOSPODARCZA_HPP_INCLUDED
