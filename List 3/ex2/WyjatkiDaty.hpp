#pragma once
#ifndef WYJATKIDATY_HPP_INCLUDED
#define WYJATKIDATY_HPP_INCLUDED

#include <string>
#include <exception>

class WyjatkiDaty : public std::exception {
  private:
    std::string s;
  public:
    WyjatkiDaty(std::string ss) throw();
    virtual ~WyjatkiDaty() throw();
    virtual const char* what() const throw();
};

#endif // WYJATKIDATY_HPP_INCLUDED
