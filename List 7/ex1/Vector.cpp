#include "Vector.hpp"

#include <cassert>
#include <iostream>

auto test_Vector(void) -> void
{
    Vector<int> v1;
    Vector<int> v2(5);
    Vector<int> v3(std::move(v2));
    v3[0]=5;
    assert(v3[0]==5);
    const Vector<int>& crv3 = v3;
    assert(crv3[0]==5);
    v1 = std::move(v3);

    assert(v1[0]==5);
    v1.swap(v3);
    assert(v3[0]==5);
    swap(v1,v3);
    assert(v1[0]==5);

    v3 = v1;
    assert(v3[0]==5);
    assert(v1[0]==5);

    Vector<int> v4(v3);
    v4.push_back(17);
    assert(v4.size()==6);
    assert(v4[5]==17);
    int i=5;
    int k=7;
    v4.push_back(i+k);
    assert(v4.size()==7);
    assert(v4.back()==12);
    v4.back()=13;
    const Vector<int>& crv4=v4;
    assert(crv4.back()==13);
    v4.pop_back();
    assert(v4.size()==6);
    assert(v4[5]==17);
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    assert(v4.size()==0);

    v4.push_front(i+k);
    v4.push_front(5);
    assert(v4[0]==5);
    v4.front()=13;
    assert(crv4[1]==12);
    assert(crv4.front()==13);
    v4.pop_back();
    assert(crv4.front()==13);
    v4.pop_front();
    assert(crv4.empty());

    std::cerr << "Klasa Vector pomyslnie przeszla testy.\n";
}
