#ifndef FilmHPP
#define FilmHPP

#include <string>
#include "Rzecz.hpp"

class Film : public Rzecz {
  private:
    std::string tytul;
    std::string rezyser;
    std::string obsada;

  public:
    Film( std::string, std::string, std::string );
    ~Film();
};

#endif
