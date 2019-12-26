#ifndef KsiazkaHPP
#define KsiazkaHPP

#include <string>
#include "Rzecz.hpp"

class Ksiazka : public Rzecz {
  private:
    std::string tytul;
    std::string autor;

  public:
    Ksiazka( std::string, std::string );
    ~Ksiazka();
};

#endif
