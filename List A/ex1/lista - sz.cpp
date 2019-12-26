#include "lista.hpp"

#include <cassert>
#include <iostream>

auto test_lista(void) -> void
{
    Lista<int> l1;
    assert(l1.empty() == true);

    l1.push_back(1);
    l1.push_back(2);
    std::cout << l1.print() << std::endl;
    l1.push_front(0);

    std::cout << l1.print() << std::endl;

    assert(l1.size() == 3);

    l1.resize(2);
    assert(l1.size() == 2);
    l1.resize(3,1);
    assert(l1.empty() == false);
    l1.resize(3);

    std::cout << l1.print() << std::endl;

    Lista<int> l2(l1);

    Lista<int> l3;
    l3 = l1;


    std::cerr << "Klasa Lista pomyslnie przeszla testy.\n";
}
