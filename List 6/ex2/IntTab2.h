#ifndef INTTAB2_H_INCLUDED
#define INTTAB2_H_INCLUDED

class IntTab2
{
  private:
    int rozmiar;
    int* tab;

  public:
    IntTab2(int r = 0);
    IntTab2(const IntTab2& a);
    ~IntTab2(void);
    IntTab2& operator=(const IntTab2 a);
    IntTab2(IntTab2&& a);
    IntTab2 operator=(IntTab2&& a);
    void swap(IntTab2& a) noexcept;
    int size(void) const;
    int operator[](int a) const;
    int& operator[](int a);
};

void swap(IntTab2& a, IntTab2& b);

#endif // INTTAB2_H_INCLUDED
