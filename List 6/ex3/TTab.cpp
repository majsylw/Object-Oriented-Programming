#include "TTab.hpp"

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

void test(void)
{
    TTab<int> it(5);
    it[0]=10;
    it[4]=20;
    assert(it.size()==5);
    assert(it[0]==10);
    assert(it[4]==20);

    TTab<int> iu(10);
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

    TTab<Grid> is(4);
    assert(is.size()==4);
    is[0] = Grid(5, 4);
    is[1] = Grid(6, -6);
    is[2] = Grid(1, -3);
    assert(is[0].X() == 5);
    assert(is[2].Y() == -3);
    assert(is[1] == Grid(6, -6));

    TTab<Grid> iz(is);
    TTab<Grid> ic(4);
    assert(iz.size() == 4);
    assert(iz[3] == Grid(0, 0));
    assert(iz[1] == Grid(6, -6));

    ic.swap(is);
    ic = iz;
    assert(ic[2].Y() == -3);
    assert(is[0] == Grid(0, 0));

    std::cerr << "Test TTab ok\n";
}
