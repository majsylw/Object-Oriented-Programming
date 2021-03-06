#include "lista2.h"

#include <cassert>
#include <sstream>
#include <iostream>

namespace maj {

    template<typename T>
    Lista<T>::Element::Element()
    : nastepny(nullptr), wartosc(T())
    {}

    template<typename T>
    Lista<T>::Element::Element(T val)
    :  nastepny(nullptr),wartosc(val)
    {}

    template<typename T>
    Lista<T>::Lista()
    : rozmiar(0), pierwszy(nullptr)
    {}

    template<typename T>
    Lista<T>::Lista(const Lista& v)
    : rozmiar(0), pierwszy(nullptr)
    {
        Element * tymczasowy = v.pierwszy;
        while(tymczasowy != nullptr)
        {
            push_back(tymczasowy->wartosc);
            tymczasowy = tymczasowy->nastepny;
        }
    }

    template<typename T>
    Lista<T>& Lista<T>::operator=(const Lista& v)
    {
        Lista k(v);
        swap(k);
        return *this;
    }

    template<typename T>
    Lista<T>::Lista(Lista&& v)
    : rozmiar(0), pierwszy(nullptr)
    {
        Element * tymczasowy = v.pierwszy;
        while( tymczasowy != nullptr )
        {
            push_back(tymczasowy->wartosc);
            tymczasowy = tymczasowy->nastepny;
        }
        v.~Lista();
    }

    template<typename T>
    Lista<T>& Lista<T>::operator=(Lista&& l) noexcept
    {
        this->~Lista();
        swap(l);
        return *this;
    }

    template<typename T>
    Lista<T>::~Lista()
    {
        while( pierwszy != nullptr )
        {
            pop_back();
        }
    }

    template<typename T>
    bool Lista<T>::empty(void) const
    {
        return (rozmiar == 0);
    }

    template<typename T>
    int Lista<T>::size() const
    {
        return rozmiar;
    }

    template<typename T>
    typename Lista<T>::Element* Lista<T>::Poczatek() const
    {
        return pierwszy;
    }

    template<typename T>
    void Lista<T>::resize(unsigned int n, const T& val /* = 0 */)
    {
        if(n < rozmiar)
        {
            for(unsigned int i = n+1; i <= rozmiar; ++i)
                pop_back();
        }
        else
        {
            for(unsigned int i = rozmiar+1; i<= n; ++i)
                push_back(val);
        }
    }

    template<typename T>
    void Lista<T>::swap(Lista& v) noexcept
    {
        using std::swap;
        swap(pierwszy, v.pierwszy);
        swap(rozmiar, v.rozmiar);
    }

    template<typename T>
    void Lista<T>::push_back(T&& a)
    {
        Element* dodany = new Element(std::move(a));
        dodany->nastepny = nullptr;

        if(pierwszy == nullptr)
        {
            pierwszy = dodany;
        }
        else
        {
            Element * tymczasowy = pierwszy;
            while( tymczasowy->nastepny != nullptr ) {
                tymczasowy = tymczasowy->nastepny;
            }

            tymczasowy->nastepny = dodany;
        }
        ++rozmiar;
    }

    template<typename T>
    void Lista<T>::push_back(const T& a)
    {
        Element* dodany = new Element(a);
        dodany->nastepny = nullptr;

        if(pierwszy == nullptr)
        {
            pierwszy = dodany;
        }
        else
        {
            Element * tymczasowy = pierwszy;
            while( tymczasowy->nastepny != nullptr ) {
                tymczasowy = tymczasowy->nastepny;
            }

            tymczasowy->nastepny = dodany;
        }
        ++rozmiar;
    }

    template<typename T>
    void Lista<T>::pop_back()
    {
        if(pierwszy != nullptr)
        {
            Element * przedostatni = nullptr;
            Element * tymczasowy = pierwszy;

            while(tymczasowy->nastepny != nullptr)
            {
                przedostatni = tymczasowy;
                tymczasowy = tymczasowy->nastepny;
            }
            delete tymczasowy;

            if( przedostatni != nullptr )
                przedostatni->nastepny = nullptr;
            else
                pierwszy = nullptr;

            --rozmiar;
        }
    }

    template<typename T>
    void Lista<T>::push_front(T&& a)
    {
        Element* dodany = new Element(std::move(a));
        dodany->nastepny = pierwszy;
        pierwszy = dodany;

        ++rozmiar;
    }

    template<typename T>
    void Lista<T>::push_front(const T& a)
    {
        Element* dodany = new Element(a);
        dodany->nastepny = pierwszy;
        pierwszy = dodany;

        ++rozmiar;
    }

    template<typename T>
    std::string Lista<T>::print() {
        std::stringstream lista;
        lista << "Lista(";
        lista << rozmiar;
        lista << "){";

        int i = 0;
        Element* element = pierwszy;
        while(element != nullptr) {
            if(i++ > 0)
                lista << ", ";
            lista << element->wartosc;
            element = element->nastepny;
        }

        lista << "}";
        return lista.str();
    }

    template<typename T>
    void swap(Lista<T>& v1, Lista<T>& v2)
    {
        v1.swap(v2);
    }

    template<typename T>
    bool operator==(const Lista<T> l1, const Lista<T> l2)
    {
        typename Lista<T>::Element * t1 = l1.Poczatek();
        typename Lista<T>::Element * t2 = l2.Poczatek();

        while( t1 != nullptr || t2 != nullptr) {
            if( t1 == nullptr || t2 == nullptr) {
                return false;
            }
            if( t1->wartosc != t2->wartosc ) {
                return false;
            }

            t1 = t1->nastepny;
            t2 = t2->nastepny;
        }

        return true;
    }

    template<typename T>
    bool operator!=(const Lista<T> l1, const Lista<T> l2)
    {
        return !(l1 == l2);
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& wyjscie, Lista<T> l)
    {
        wyjscie << "{";
        int i = 0;
        typename Lista<T>::Element * element = l.Poczatek();
        while(element != nullptr) {
            if(i++ > 0)
                wyjscie << ", ";
            wyjscie << element->wartosc;
            element = element->nastepny;
        }

        wyjscie << "}";

        return wyjscie;
    }

    template<typename T>
    Lista<T>::Iterator::Iterator(Element* el)
    : aktualny(el)
    {}

    template<typename T>
    Lista<T>::Iterator::~Iterator() = default;

    template<typename T>
    typename Lista<T>::Element* Lista<T>::Iterator::Aktualny() const
    {
        return aktualny;
    }

    template<typename T>
    typename Lista<T>::Iterator& Lista<T>::Iterator::operator++() //preinkrementacja
    {
        if(aktualny != nullptr)
            aktualny = aktualny->nastepny;
        return *this;
    }

    template<typename T>
    typename Lista<T>::Iterator Lista<T>::Iterator::operator++(int) //postinkrementacja
    {
        Iterator *kopia = this;
        ++(*this);
        return *kopia;
    }

    template<typename T>
    T* Lista<T>::Iterator::operator->() const
    {
        return &(aktualny->wartosc);
    }

    template<typename T>
    T* Lista<T>::Iterator::operator->()
    {
        return &(aktualny->wartosc);
    }

    template<typename T>
    T Lista<T>::Iterator::operator*() const
    {
        return aktualny->wartosc;
    }

    template<typename T>
    T Lista<T>::Iterator::operator*()
    {
        return aktualny->wartosc;
    }

    template<typename T>
    bool Lista<T>::Iterator::operator==(typename Lista<T>::Iterator podany)
    {
        if(aktualny != podany.aktualny)
            return false;
        else
            return true;
    }

    template<typename T>
    bool Lista<T>::Iterator::operator!=( typename Lista<T>::Iterator podany ) {
        return !(this == podany);
    }

    template<typename T>
    typename Lista<T>::Iterator Lista<T>::begin()
    {
        Iterator b(pierwszy);
        return b;
    }

    template<typename T>
    typename Lista<T>::const_iterator Lista<T>::begin() const
    {
        Iterator b(pierwszy);
        return b;
    }

    template<typename T>
    typename Lista<T>::Iterator Lista<T>::end()
    {
        Element * ostatni = pierwszy;
        if(ostatni == nullptr)
            return Iterator(ostatni);

        while( ostatni->nastepny != nullptr) {
            ostatni = ostatni->nastepny;
        }
        return Iterator(ostatni->nastepny);
    }

    template<typename T>
    typename Lista<T>::const_iterator Lista<T>::end() const
    {
        Element* ostatni = pierwszy;
        if(ostatni == nullptr)
            return Iterator( ostatni );

        while(ostatni->nastepny != nullptr) {
            ostatni = ostatni->nastepny;
        }
        return Iterator(ostatni->nastepny);
    }

    template<typename T>
    void Lista<T>::erase(const_iterator iter)
    {
        if(iter.Aktualny() != nullptr){
                Element* tymczasowy = pierwszy;

            if( tymczasowy == iter.Aktualny() ) {
                pierwszy = tymczasowy->nastepny;
                delete iter.Aktualny();
            } else {
                while( tymczasowy->nastepny != iter.Aktualny() && tymczasowy->nastepny != nullptr )
                {
                    tymczasowy = tymczasowy->nastepny;
                }

                if(tymczasowy->nastepny == iter.Aktualny()) {
                    tymczasowy->nastepny = iter.Aktualny()->nastepny;
                    delete iter.Aktualny();
                }
            }
            --rozmiar;
        }
    }
}

class Grid
{
    private:
        int x_, y_;

    public:
        Grid(int x=0, int y=0) : x_(x), y_(y) {}
        int X(void) const { return x_; }
        int Y(void) const { return y_; }
};

bool operator==(Grid g1, Grid g2)
{
    return (g1.X()==g2.X())&&(g1.Y()==g2.Y());
}

std::ostream& operator<<(std::ostream& wy, Grid g)
{
    return wy<<'('<<g.X()<<','<<g.Y()<<')';
}

auto test_lista(void) -> void
{
    maj::Lista<int> l1;
    assert(l1.empty());

    l1.push_back(1);
    l1.push_back(2);

    assert(l1.print() == "Lista(2){1, 2}");
    l1.push_front(0);
    assert(l1.size() == 3);

    assert(l1.print() == "Lista(3){0, 1, 2}");

    l1.resize(2);
    assert(l1.size() == 2);
    l1.resize(3,1);
    assert(!l1.empty());
    l1.resize(3);

    maj::Lista<int> l4;
    l4.push_back(2);
    l4.push_front(3);
    l4.push_front(4);
    l4.push_back(1);

    assert(l1 != l4);

    swap(l1,l4);
    std::ostringstream wy1;
    wy1 << l1;
    assert(wy1.str() == "{4, 3, 2, 1}");
    l1.swap(l4);
    std::ostringstream wy2;
    wy2 << l1;
    assert(wy2.str() == "{0, 1, 1}");

    l4.pop_back();
    assert(l4.size() == l1.size());
    assert(l4 != l1);

    maj::Lista<int> l2(l1);
    assert(l2 == l1);

    l2.push_back(4);
    assert(l2 != l1);
    assert(l2.print() == "Lista(4){0, 1, 1, 4}");

    maj::Lista<int> l3;
    l3 = l1;
    assert(l3.print() == "Lista(3){0, 1, 1}");
    maj::Lista<int> v1;
    v1.push_back(1);
    v1 = std::move(l2);
    std::ostringstream wy3;
    wy3 << v1;
    assert(wy3.str() == "{0, 1, 1, 4}");
    assert(v1.print() == "Lista(4){0, 1, 1, 4}");;
    assert(l2.empty());

    maj::Lista<int> v2(std::move(v1));
    assert(v2.print() == "Lista(4){0, 1, 1, 4}");
    assert(v1.empty());

    maj::Lista<char> s1;
    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');

    maj::Lista<char> s2;
    s2.push_back('a');
    s2.push_back('b');
    s2.push_back('d');

    assert(s2 != s1);

    assert(*(s2.begin()) == 'a');
    s2.push_front('e');
    assert(*(s2.begin()) == 'e');
    s2.push_back('f');
    assert(*(s1.begin()) != *(s2.begin()));

    maj::Lista<char>::Iterator a = s1.begin();
    a++;
    assert(*(a) == 'b');
    ++a;
    assert(*(a) == 'c');

    s1.erase(s1.begin());
    assert(*(s1.begin()) == 'b');
    assert(*(a) == 'c');

    Grid g1[] = {{1,2},{3,4},{5,6},{7,8},{9,0}};
    maj::Lista<Grid> lg1;
    lg1.push_back(g1[0]);
    lg1.push_back(g1[1]);
    lg1.push_back(g1[2]);
    lg1.push_back(g1[3]);
    lg1.push_back(g1[4]);

    maj::Lista<Grid>::Iterator b = lg1.begin();

    assert(b -> X() == 1);

    lg1.erase(lg1.end());

    std::cerr << "Klasa Lista pomyslnie przeszla testy.\n";
}
