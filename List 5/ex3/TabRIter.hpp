#pragma once
#ifndef TABRITER_HPP_INCLUDED
#define TABRITER_HPP_INCLUDED

#include<cassert>

/*template<typename Value>
class TabRIter;

template<typename T>
TabRIter<T> rbegin(T* tab, int rozmiar)
{
    TabRIter<T> a(tab+rozmiar-1,tab,rozmiar);
    return a;
}

template<typename T>
TabRIter<T> rend(T* tab, int rozmiar)
{
    TabRIter<T> a(tab+rozmiar,tab,rozmiar);
    return a;
}*/

template<typename Value>
class TabRIter
{
    Value* wartosc;
    Value* poczatek;
    int rozmiar;

    TabRIter(Value* w = nullptr, Value* p = nullptr, int r = 0)
    : wartosc(w), poczatek(p), rozmiar(r)
    {}

public:

    /*Value& operator*(void)
    {
        Value* tmp = wartosc - 1;
        return *tmp;
    }

    Value* operator->(void)
    {
        return &(operator*());
    }*/

    Value& operator*(void)
    {
        return *wartosc;
    }

    Value* operator->(void)
    {
        return wartosc;
    }

    explicit operator bool() const
    {
        return (wartosc != nullptr);
    }


    TabRIter& operator++()  // preinkrementacje, czyli najpierw  zmniejszamy(odwrotnie do znakow) a potem zwracamy
    {
        assert(wartosc != nullptr);
        assert(wartosc != poczatek + rozmiar);

        if(wartosc == poczatek)
            wartosc = poczatek+rozmiar;
        else
            --wartosc;

        return *this;
    }

    TabRIter operator++(int) {  // specjalny zapis do postinkrementacji

        TabRIter kopia = (*this);

        ++(*this);

        return kopia; // zwracamy kopie, a nie oryginal
    }

    TabRIter& operator--()  // predekrementacje, czyli najpierw  zwiekszamy a potem zwracamy
    {
        assert(wartosc != nullptr);
        assert(wartosc != poczatek + rozmiar - 1);

        if(wartosc == poczatek + rozmiar)
            wartosc = poczatek;
        else
            ++wartosc;

        return *this;
    }

    TabRIter operator--(int)   // specjalny zapis do postdekrementacji
    {
        TabRIter kopia = (*this);

        --(*this);

        return kopia; // zwracamy kopie, a nie oryginal
    }

    bool operator==(const TabRIter& a) const {return wartosc==a.wartosc;}
    bool operator!=(const TabRIter& a) const {return wartosc!=a.wartosc;}

    Value* ZwrocAdres(void) const
    {
      return wartosc;
    }

    static TabRIter rbegin(Value* tab, int rozmiar)
    {
        TabRIter a(tab+rozmiar-1,tab,rozmiar);
        return a;
    }

    static TabRIter rend(Value* tab, int rozmiar)
    {
        TabRIter a(tab+rozmiar,tab,rozmiar);
        return a;
    }

};

template<typename Value>
bool operator==(const TabRIter<Value>& a, const TabRIter<Value>& b)
{
  return (a.ZwrocAdres() == b.ZwrocAdres());
}

template<typename Value>
bool operator!=(const TabRIter<Value>& a, const TabRIter<Value>& b)
{
  return !(a == b);
}

template<typename T>
TabRIter<T> rbegin(T* tab, int rozmiar)
{
    return TabRIter<T>::rbegin(tab,rozmiar);
}

template<typename T>
TabRIter<T> rend(T* tab, int rozmiar)
{
    return TabRIter<T>::rend(tab,rozmiar);
}

class Grid;

void test_TabRIter(void);

#endif // TABRITER_HPP_INCLUDED
