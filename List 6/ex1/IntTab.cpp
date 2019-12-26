#include "IntTab.hpp"

#include <iostream>
#include <algorithm>
#include <cassert>


IntTab::IntTab(int r)
: rozmiar(r), tab(nullptr)
{
    if (rozmiar > 0)
        tab = new int[r];
}

IntTab::IntTab(const IntTab& a)
: rozmiar(a.rozmiar), tab(nullptr)
{
    if (a.tab)
    {
        tab = new int[a.rozmiar];
        std::copy(a.tab, a.tab + a.rozmiar, tab);
    }
}

IntTab& IntTab::operator=(IntTab a)
{
    swap(a);
    return *this;
}

IntTab::~IntTab(void)
{
    delete[] tab;
}

void IntTab::swap(IntTab& a) noexcept
{
    using std::swap;
    swap(tab, a.tab);
    swap(rozmiar, a.rozmiar);
}

int IntTab::size(void) const
{
    return rozmiar;
}

int IntTab::operator[](int a) const
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

int& IntTab::operator[](int a)
{
    assert(0 <= a && a < rozmiar);

    return tab[a];
}

void swap(IntTab& a, IntTab& b)
{
    a.swap(b);
}

void test_IntTab(void)
{
    IntTab it(5);
    it[0]=10;
    it[4]=20;
    assert(it.size()==5);
    assert(it[0]==10);
    assert(it[4]==20);

    IntTab iu(10);
    iu[0]=17;
    iu[4]=34;
    assert(iu.size()==10);
    assert(iu[0]==17);
    assert(iu[4]==34);

    iu.swap(it);
    assert(iu.size()==5);
    assert(iu[0]==10);
    assert(it.size()==10);
    assert(it[0]==17);

    IntTab is(iu);
    assert(is.size()==5);
    assert(is[0]==10);

    IntTab iw;
    iw = it;
    assert(iw.size()==10);
    assert(iw[0]==17);

    it[0]=1;
    iu[0]=2;
    is[0]=3;
    iw[0]=4;

    assert(it[0]==1);
    assert(iu[0]==2);
    assert(is[0]==3);
    assert(iw[0]==4);

    std::cerr << "Test InTab ok\n";
}
