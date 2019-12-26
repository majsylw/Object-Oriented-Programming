#include "IntTab2.h"

#include <iostream>
#include <algorithm>
#include <cassert>

IntTab2::IntTab2(int r)
: rozmiar(r), tab(nullptr)
{
    if (r > 0)
        tab = new int[r];
}

IntTab2::IntTab2(const IntTab2& a)
: rozmiar(a.rozmiar), tab(nullptr)
{
    if (a.tab)
    {
        tab = new int[a.rozmiar];
        std::copy(a.tab, a.tab + a.rozmiar, tab);
    }
}

IntTab2& IntTab2::operator=(IntTab2 a)
{
    swap(a);
    return *this;
}

IntTab2::~IntTab2(void)
{
    delete[] tab;
}

IntTab2 IntTab2::operator=(IntTab2&& a)
{
    swap(a);
    return *this;
}

IntTab2::IntTab2(IntTab2&& a)
: rozmiar(0), tab(nullptr)
{
    swap(a);
}

void IntTab2::swap(IntTab2& a) noexcept
{
    using std::swap;
    swap(tab, a.tab);
    swap(rozmiar, a.rozmiar);
}

int IntTab2::size(void) const
{
    return rozmiar;
}

int IntTab2::operator[](int a) const
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

int& IntTab2::operator[](int a)
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

void swap(IntTab2& a, IntTab2& b)
{
    a.swap(b);
}
