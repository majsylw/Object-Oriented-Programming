#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <algorithm>
#include <cassert>
#include <memory>
#include <utility>

template<class T>
class Vector
{
private:
    std::unique_ptr<T[]> wsk;
    int rozmiar;

public:

    explicit Vector(int r = 0)
    : wsk(r ? (new T[r]) : nullptr), rozmiar(r)
    {}

    Vector(const Vector& v)
    : wsk(v.size() ? (new T[v.size()]) : nullptr), rozmiar(v.rozmiar)
    {
          std::copy_n(v.wsk.get(), rozmiar, wsk.get());
    }

    Vector& operator=(const Vector& v)
    {
        Vector k(v);
        swap(k);
        return *this;
    }

    Vector(Vector&&) = default;

    Vector& operator=(Vector&&) noexcept = default;

    int size(void) const
    {
        return rozmiar;
    }

    bool empty(void) const
    {
        return (rozmiar == 0);
    }

    void swap(Vector& v) noexcept
    {
        using std::swap;
        swap(wsk, v.wsk);
        swap(rozmiar, v.rozmiar);
    }

    T& operator[](int i)
    {
    return wsk[i];
    }

    const T& operator[](int i) const
    {
        return wsk[i];
    }

    void push_back(T&& a)
    {
        std::unique_ptr<T[]> A(new T[rozmiar + 1]);
        std::transform(wsk.get(), wsk.get() + rozmiar, A.get(), std::move_if_noexcept<T>);
        A[rozmiar] = std::move(a);
        ++rozmiar;
        wsk = std::move(A);
    }

    void push_back(const T& a)
    {
        std::unique_ptr<T[]> A(new T[rozmiar + 1]);
        std::move(wsk.get(), wsk.get() + rozmiar, A.get());
        A[rozmiar] = a;
        ++rozmiar;
        wsk = std::move(A);
    }

    void push_front(T&& a)
    {
        std::unique_ptr<T[]> A(new T[rozmiar + 1]);
        std::move(wsk.get(), wsk.get() + rozmiar, A.get() + 1);
        A[0] = std::move(a);
        ++rozmiar;
        wsk = std::move(A);
    }

    void push_front(const T& a)
    {
        std::unique_ptr<T[]> A(new T[rozmiar + 1]);
        std::move(wsk.get(), wsk.get() + rozmiar, A.get() + 1);
        A[0] = a;
        ++rozmiar;
        wsk = std::move(A);
    }

    void pop_back(void)
    {
        --rozmiar;
        std::unique_ptr<T[]> A(new T[rozmiar]);
        std::move(wsk.get(), wsk.get() + rozmiar, A.get());
        wsk = std::move(A);
    }

    void pop_front(void)
    {
        --rozmiar;
        std::unique_ptr<T[]> A(new T[rozmiar]);
        std::move(wsk.get() + 1, wsk.get() + rozmiar + 1, A.get());
        wsk = std::move(A);
    }

    T& back(void)
    {
        return wsk[rozmiar-1];
    }

    const T& back(void) const
    {
        return wsk[rozmiar-1];
    }

    T& front(void)
    {
        return wsk[0];
    }

    const T& front(void) const
    {
        return wsk[0];
    }

  };

template<typename T>
void swap(Vector<T>& v1, Vector<T>& v2)
{
    v1.swap(v2);
}

void test_Vector(void);

#endif // VECTOR_HPP_INCLUDED
