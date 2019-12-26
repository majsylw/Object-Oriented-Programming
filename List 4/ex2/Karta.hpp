#pragma once
#ifndef KARTA_HPP_INCLUDED
#define KARTA_HPP_INCLUDED

#include <string>
#include <exception>

class Karta
{
    std::string numer;
public:
    Karta(std::string nr);
    class ZlyNumer: public std::exception
    {
    private:
        char wrong[40];
    public:
        ZlyNumer(std::string w);
        const char* what(void) const noexcept override;
    };

    class ZlaSuma: public ZlyNumer
    {
    private:
        char blad[40];
    public:
        ZlaSuma(std::string b);
        const char* what(void) const noexcept override;
    };

    std::string ZwrocNumer(void) const;
};

void test_Karty();

#endif // KARTA_HPP_INCLUDED
