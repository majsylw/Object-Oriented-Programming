#include "HeapOptional.hpp"

#include "Data.hpp"

#include<iostream>
#include<cassert>
#include <memory>

class Grid
{
    int x_, y_;
  public:
    Grid(int x=0, int y=0) : x_(x), y_(y) {}
    ~Grid(){};
    int X(void) const {return x_;}
    int Y(void) const {return y_;}
};
bool operator==(Grid g1, Grid g2)
{
  return (g1.X()==g2.X())&&(g1.Y()==g2.Y());
}

struct Foo
{
    bool licznik=false;

    ~Foo()
    {
        licznik = true;
    }

};

std::ostream& operator<<(std::ostream& wy, Grid g)
{
  return wy<<'('<<g.X()<<','<<g.Y()<<')';
}

void testy()
{
    HeapOptional<Data> ho(new Data(2014,11,4));
    assert(ho->podaj_rok() == 2014);
    assert((*ho).podaj_miesiac() == 11);

    HeapOptional<Data> ho2;
    ho2.reset(new Data(1970,1,1));
    assert(ho);

    HeapOptional<Data> h1(new Data(2014,10,19));
    HeapOptional<Data> h2(h1);
    HeapOptional<Data> h3 = ho2;

    assert(h3->podaj_dzien() == 1);
    assert(h1->podaj_dzien() == 19);

    HeapOptional<Grid> g(new Grid(2,1));
    assert(g->X() == 2);
    assert((*g).Y() == 1);
    HeapOptional<Grid> g2(g);
    HeapOptional<Grid> g3 = g2;


    assert(g3->X() == 2);
    assert((*g2).Y() == 1);

    HeapOptional<Grid> w;
    Grid* w1 = w.GetPointer();
    w.reset(new Grid());
    assert(w.GetDelete() == 0);
    Grid* w2 = w.GetPointer();
    w = new Grid();
    assert(w.GetDelete() == 1);
    Grid* w3 = w.GetPointer();
    w.reset();

    std::cerr << "Program pomyslnie przeszedl testy.\n";



}
