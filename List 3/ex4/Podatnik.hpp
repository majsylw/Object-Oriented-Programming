#ifndef PODATNIK_HPP_INCLUDED
#define PODATNIK_HPP_INCLUDED

#include <string>

class Podatnik
{
  public:
    virtual std::string Dane(void){};
    virtual ~Podatnik(void){};
};

#endif // PODATNIK_HPP_INCLUDED
