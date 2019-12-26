#include "IntTab3.h"

#include <iostream>
#include <algorithm>
#include <cassert>

IntTab3::IntTab3(int r)
: rozmiar(r), tab(nullptr)
{
    if (r > 0)
        tab = new int[r];
}

IntTab3::IntTab3(const IntTab3& a)
: rozmiar(a.rozmiar), tab(nullptr)
{
    if (a.tab)
    {
        tab = new int[a.rozmiar];
        std::copy(a.tab, a.tab + a.rozmiar, tab);
    }
}

IntTab3& IntTab3::operator=(IntTab3 a)
{
    swap(a);
    return *this;
}

IntTab3::~IntTab3(void)
{
    delete[] tab;
}

void IntTab3::swap(IntTab3& a) noexcept
{
    using std::swap;
    swap(tab, a.tab);
    swap(rozmiar, a.rozmiar);
}

int IntTab3::size(void) const
{
    return rozmiar;
}

int IntTab3::operator[](int a) const
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

int& IntTab3::operator[](int a)
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

void swap(IntTab3& a, IntTab3& b)
{
    a.swap(b);
}
