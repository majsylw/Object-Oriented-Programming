#pragma once
#ifndef TABLEOPTIONAL_HPP_INCLUDED
#define TABLEOPTIONAL_HPP_INCLUDED

#include<cassert>
#include<iostream>

template<typename Value>
class TableOptional
{
    Value* tab;
    int el;

public:
    TableOptional(Value* t = nullptr, int l = 0)
    : tab(t), el(l)
    {}

    ~TableOptional(void)
    {
        if (tab != nullptr) {
		delete[] tab;
		tab = nullptr;
        }
    }

    Value operator[](int indeks) const
    {
        assert(indeks > -1);
        assert(indeks < el);

        return *(tab+indeks);
    }

    Value& operator[](int indeks)
    {
        assert(indeks > -1);
        assert(indeks < el);

        return *(tab+indeks);
    }

    explicit operator bool() const
    {
        return (tab != nullptr);
    }

    TableOptional(const TableOptional& n) = delete;

    TableOptional& operator=(const TableOptional& n) = delete;

    void reset(Value* value=nullptr, int a = 0)
    {
        if(tab!=nullptr)
            delete[] tab;
        tab = value;
        el = a;
    }

    int ilosc() const
    {
        return el;
    }

    void swap(TableOptional& a)
    {
        using std::swap;
        swap(tab, a.tab);
        swap(el, a.el);
    }
};

template<typename T>
void swap(TableOptional<T>& a, TableOptional<T>& b)
{
  a.swap(b);
}

void testy_TableOptional(void);


#endif // TABLEOPTIONAL_HPP_INCLUDED
