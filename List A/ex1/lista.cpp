#include "lista.hpp"

#include <cassert>
#include <sstream>
#include <iostream>

using namespace maj;

auto test_lista(void) -> void
{
    Lista<int> l1;
    assert(l1.empty());

    l1.push_back(1);
    l1.push_back(2);
    assert(l1.print() == "Lista(2){1, 2}");
    l1.push_front(0);
    assert(l1.size() == 3);

    assert(l1.print() == "Lista(3){0, 1, 2}");

    l1.resize(2);
    assert(l1.size() == 2);
    l1.resize(3,1);
    assert(!l1.empty());
    l1.resize(3);

    Lista<int> l4;
    l4.push_back(2);
    l4.push_front(3);
    l4.push_front(4);
    l4.push_back(1);

    assert(l1 != l4);

    swap(l1,l4);
    std::ostringstream wy1;
    wy1 << l1;
    assert(wy1.str() == "{4, 3, 2, 1}");
    l1.swap(l4);
    std::ostringstream wy2;
    wy2 << l1;
    assert(wy2.str() == "{0, 1, 1}");

    l4.pop_back();
    assert(l4.size() == l1.size());
    assert(l4 != l1);

    Lista<int> l2(l1);
    assert(l2 == l1);

    l2.push_back(4);
    assert(l2 != l1);
    assert(l2.print() == "Lista(4){0, 1, 1, 4}");

    Lista<int> l3;
    l3 = l1;
    assert(l3.print() == "Lista(3){0, 1, 1}");
    Lista<int> v1;
    v1.push_back(1);
    v1 = std::move(l2);
    std::ostringstream wy3;
    wy3 << v1;
    assert(wy3.str() == "{0, 1, 1, 4}");
    assert(v1.print() == "Lista(4){0, 1, 1, 4}");;
    assert(l2.empty());

    Lista<int> v2(std::move(v1));
    assert(v2.print() == "Lista(4){0, 1, 1, 4}");
    assert(v1.empty());
    v1.push_back(2);

    Lista<char> s1;
    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');

    Lista<char> s2;
    s2.push_back('a');
    s2.push_back('b');
    s2.push_back('d');

    assert(s2 != s1);

    std::cerr << "Klasa Lista pomyslnie przeszla testy.\n";
}
