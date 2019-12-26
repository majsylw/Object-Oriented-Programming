#ifndef FirmaHPP
#define FirmaHPP

#include <string>
#include "Klient.hpp"

class Firma : public Klient {
  private:
    std::string nazwa;

  public:
    Firma( std::string );
    ~Firma();
};

#endif
