#ifndef INTTAB3_H_INCLUDED
#define INTTAB3_H_INCLUDED

class IntTab3
{
  private:
    int rozmiar;
    int* tab;

  public:
    IntTab3(int r = 0);
    IntTab3(const IntTab3& a);
    ~IntTab3(void);
    IntTab3& operator=(const IntTab3 a);
    void swap(IntTab3& a) noexcept;
    int size(void) const;
    int operator[](int a) const;
    int& operator[](int a);
};

void swap(IntTab3& a, IntTab3& b);

#endif // INTTAB3_H_INCLUDED
