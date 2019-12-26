#include "IntTab1.h"

#include <iostream>
#include <algorithm>
#include <cassert>

IntTab1::IntTab1(int r)
: rozmiar(r), tab(nullptr)
{
    if (r > 0)
        tab = new int[r];
}

IntTab1::IntTab1(const IntTab1& a)
: rozmiar(a.rozmiar), tab(nullptr)
{
    if (a.tab)
    {
        tab = new int[a.rozmiar];
        std::copy(a.tab, a.tab + a.rozmiar, tab);
    }
}

IntTab1& IntTab1::operator=(IntTab1 a)
{
    swap(a);
    return *this;
}

IntTab1::~IntTab1(void)
{
    delete[] tab;
}

IntTab1 IntTab1::operator=(IntTab1&& a) noexcept
{
    swap(a);
    return *this;
}

IntTab1::IntTab1(IntTab1&& a) noexcept
: rozmiar(0), tab(nullptr)
{
    swap(a);
}

void IntTab1::swap(IntTab1& a) noexcept
{
    using std::swap;
    swap(tab, a.tab);
    swap(rozmiar, a.rozmiar);
}

int IntTab1::size(void) const
{
    return rozmiar;
}

int IntTab1::operator[](int a) const
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

int& IntTab1::operator[](int a)
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

void swap(IntTab1& a, IntTab1& b)
{
    a.swap(b);
}
