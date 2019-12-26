#pragma once
#ifndef BRAKKLUCZA_HPP_INCLUDED
#define BRAKKLUCZA_HPP_INCLUDED

#include <string>
#include <exception>


class BrakKlucza : public std::exception {
  private:
    std::string s;
  public:
    BrakKlucza(std::string ss) throw();
    virtual ~BrakKlucza() throw();
    virtual const char* what() const throw();
};


#endif // BRAKKLUCZA_HPP_INCLUDED
