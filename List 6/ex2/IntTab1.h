#ifndef INTTAB1_H_INCLUDED
#define INTTAB1_H_INCLUDED

class IntTab1
{
  private:
    int rozmiar;
    int* tab;

  public:
    IntTab1(int r = 0);
    IntTab1(const IntTab1& a);
    ~IntTab1(void);
    IntTab1& operator=(const IntTab1 a);
    IntTab1(IntTab1&& a) noexcept;
    IntTab1 operator=(IntTab1&& a) noexcept;
    void swap(IntTab1& a) noexcept;
    int size(void) const;
    int operator[](int a) const;
    int& operator[](int a);
};

void swap(IntTab1& a, IntTab1& b);

#endif // INTTAB1_H_INCLUDED
