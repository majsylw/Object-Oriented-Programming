#pragma once
#ifndef NWD_HPP_INCLUDED
#define NWD_HPP_INCLUDED

#include <cassert>

template <typename T>
T nwd(T a,T b)
{
    assert(a > 0);
    assert(b > 0);

    T c;

    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void test_NWDtemplate(void);

#endif // NWD_HPP_INCLUDED
