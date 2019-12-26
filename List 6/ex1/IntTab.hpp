#ifndef INTTAB_HPP_INCLUDED
#define INTTAB_HPP_INCLUDED

class IntTab
{
  private:
    int rozmiar;
    int* tab;

  public:
    IntTab(int r = 0);
    IntTab(const IntTab& a);
    ~IntTab(void);
    IntTab& operator=(const IntTab a);
    void swap(IntTab& a) noexcept;
    int size(void) const;
    int operator[](int a) const;
    int& operator[](int a);
};

void swap(IntTab& a, IntTab& b);

void test_IntTab(void);

#endif // INTTAB_HPP_INCLUDED
