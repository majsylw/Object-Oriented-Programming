#include "TableOptional.hpp"

#include<iostream>

class Grid
{
    int x_, y_;
  public:
    Grid(int x=0, int y=0) : x_(x), y_(y) {}
    int X(void) const {return x_;}
    int Y(void) const {return y_;}
};
bool operator==(Grid g1, Grid g2)
{
  return (g1.X()==g2.X())&&(g1.Y()==g2.Y());
}
std::ostream& operator<<(std::ostream& wy, Grid g)
{
  return wy<<'('<<g.X()<<','<<g.Y()<<')';
}

void testy_TableOptional(void)
{
    TableOptional<int> ho(new int[5]{1,2,3,4,5},5);
    assert(ho[0] == 1);
    assert(ho[1] == 2);
    assert(ho[2] == 3);
    assert(ho[3] == 4);
    assert(ho[4] == 5);

    ho[2] = 7;
    assert(ho[2] = 7);

    TableOptional<char> ho2;
    ho2.reset(new char[4]{'a','b','c','d'},4);

    assert(ho2);
    assert(ho.ilosc() != ho2.ilosc());

    TableOptional<int> h3(new int[4]{22,23,34,98},4);
    ho.swap(h3);
    assert(ho.ilosc() == 4);
    assert(h3.ilosc() == 5);

    TableOptional<Grid> g(new Grid[6]{Grid(1,2),Grid(3,4),Grid(5,6),Grid(7,8),Grid(9,0)},6);

    assert(g[5] == Grid(0,0));

    std::cerr << "Klasa pomyslnie przeszla testy \n";
}
