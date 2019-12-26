#ifndef TTAB_HPP_INCLUDED
#define TTAB_HPP_INCLUDED

#include<iostream>
#include<algorithm>
#include<cassert>

template<typename T>
class TTab
{
  private:
    int rozmiar;
    T* tab;

  public:

      TTab(int r)
      :rozmiar(r), tab(nullptr)
      {
          if (r > 0)
            tab = new T[r];
      }

      TTab(const TTab& a)
      :rozmiar(a.rozmiar), tab(nullptr)
      {
          if (a.tab)
          {
              tab = new T[a.rozmiar];
              std::copy(a.tab, a.tab + a.rozmiar, tab);
              /*while (a.tab != a.tab + rozmiar)
              {
                *tab++ = *a.tab++;
              }*/
          }
      }

      TTab& operator=(TTab a)
      {
          swap(a);
          return *this;
      }

      ~TTab(void)
      {
          delete[] tab_;
      }

      void swap(TTab& a) noexcept
      {
          using std::swap;
          swap(tab, a.tab);
          swap(rozmiar, a.rozmiar);
      }

      int size(void) const
      {
          return rozmiar;
      }

      T operator[](int a) const
      {
          assert(0 <= a && a < rozmiar);

          return tab[a];
      }

      T& operator[](int a)
      {
          assert(0 <= a && a < rozmiar);

          return tab[a];
      }
};

template<typename T>
void swap(TTab<T>& a, TTab<T>& b)
{
    a.swap(b);
}

void test(void);

#endif // TTAB_HPP_INCLUDED
