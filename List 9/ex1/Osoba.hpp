#ifndef OsobaHPP
#define OsobaHPP

#include <string>
#include "Klient.hpp"

class Osoba : public Klient {
  private:
    std::string imie;
    std::string nazwisko;

  public:
    Osoba( std::string, std::string );
    ~Osoba();
};

#endif
