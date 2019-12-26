#include "nwd.hpp"

#include <iostream>

void test_NWDtemplate(void)
{
    assert(nwd(12,40) == 4);
    assert(nwd(83,23) == 1);


    std::cerr << "Funkcja NWD pomyslnie przeszla testy. \n";
}
