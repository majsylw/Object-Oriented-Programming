#pragma once
#ifndef HEAPOPTIONAL_HPP_INCLUDED
#define HEAPOPTIONAL_HPP_INCLUDED

#include<iostream>

template<typename Value>
class HeapOptional
{
    Value* wartosc;
    int licznik;

public:
    HeapOptional(Value* w = nullptr)
    {
            wartosc = w;
            licznik = 0;
    }

    ~HeapOptional(void)
    {
        delete wartosc;
        wartosc = nullptr;
    }

    const Value operator*(void)
    {
        return *wartosc;
    }

    const Value* operator->(void) const
    {
        return wartosc;
    }

    explicit operator bool() const
    {
        return (wartosc != nullptr);
    }

    HeapOptional(const HeapOptional& n)
    :wartosc(nullptr)
    {
        //if(this != &n)
        //{
            wartosc = new Value( *n.wartosc );
            licznik = n.licznik;
        //}
    }

    HeapOptional& operator=(HeapOptional& n)
    {

    //if(this != &n){
        if(wartosc != nullptr)
        {
            delete wartosc;
            licznik++;
        }
        wartosc = new Value(*(n.wartosc));

    //}
    return *this;
    }

    HeapOptional& operator=(Value* n)
    {
        if(wartosc != nullptr) {
            delete wartosc;
            licznik ++;
        }
        wartosc = n;
        return *this;
    }

    void reset(Value* value=nullptr)
    {
        if(wartosc != nullptr)
        {
            delete wartosc;
            licznik ++;
        }
        wartosc = value;
    }

    Value* GetPointer() {return wartosc;}
    int GetDelete() {return licznik;}
};

void testy(void);

#endif // HEAPOPTIONAL_HPP_INCLUDED
