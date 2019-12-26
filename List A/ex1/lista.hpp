#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include<string>
#include<sstream>

namespace maj
{
    template<class T>
    class Lista
    {
        private:
            struct Element
            {
                Element* nastepny;
                T wartosc;
                Element(T val)
                : wartosc(val)
                {}
            };
            unsigned int rozmiar;
            Element* pierwszy;
            Element* ostatni;

        public:
            Lista()
            : rozmiar(0), pierwszy(nullptr), ostatni(nullptr)
            {}

            Lista(const Lista& v)
            : rozmiar(0)
            {
                if(v.rozmiar > 0)
                {
                    Element* tymczasowy = v.pierwszy;
                    while(tymczasowy->nastepny != v.pierwszy)
                    {
                        push_back(tymczasowy->wartosc);
                        tymczasowy = tymczasowy->nastepny;
                    }
                    push_back(v.ostatni->wartosc);
                }
            }

            Lista& operator=(const Lista& v)
            {
                Lista k(v);
                swap(k);
                return *this;
            }

            Lista(Lista&& v)
            : rozmiar(0)
            {
                if(v.rozmiar > 0)
                {
                    Element* tymczasowy = v.pierwszy;
                    while(tymczasowy->nastepny != v.pierwszy)
                    {
                        push_back(tymczasowy->wartosc);
                        tymczasowy = tymczasowy->nastepny;
                    }
                    push_back(v.ostatni->wartosc);
                }
                v.~Lista();
            }

            Lista& operator=(Lista&& l) noexcept
            {
                this->~Lista();
                swap(l);
                return *this;
            }

            ~Lista()
            {
                while(rozmiar > 0)
                {
                    pop_back();
                }
            }

            bool empty(void) const
            {
                return (rozmiar == 0);
            }

            int size() const
            {
                return rozmiar;
            }

            Element* Poczatek() const
            {
                return pierwszy;
            }

            void resize(unsigned int n, const T& val = 0)
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
                rozmiar = n;
            }

            void swap(Lista& v) noexcept
            {
                using std::swap;
                swap(pierwszy, v.pierwszy);
                swap(ostatni, v.ostatni);
                swap(rozmiar, v.rozmiar);
            }

            void push_back(T&& a)
            {
                Element* dodany = new Element(std::move(a));
                if(rozmiar == 0)
                {
                    dodany->nastepny = dodany;
                    pierwszy = dodany;
                    ostatni = dodany;
                }
                else
                {
                    ostatni->nastepny = dodany;
                    dodany->nastepny = pierwszy;
                    ostatni = dodany;
                }
                ++rozmiar;
            }

            void push_back(const T& a)
            {
                Element* dodany = new Element(a);
                if(rozmiar == 0)
                {
                    dodany->nastepny = dodany;
                    pierwszy = dodany;
                    ostatni = dodany;
                }
                else
                {
                    ostatni->nastepny = dodany;
                    dodany->nastepny = pierwszy;
                    ostatni = dodany;
                }
                ++rozmiar;
            }

            void pop_back()
            {
                if(rozmiar > 0)
                {
                    Element* tymczasowy = pierwszy;
                    while(tymczasowy->nastepny != ostatni)
                    {
                        tymczasowy = tymczasowy->nastepny;
                    }
                    tymczasowy->nastepny = pierwszy;
                    delete ostatni;
                    ostatni = tymczasowy;
                    --rozmiar;
                }
            }

            void push_front(T&& a)
            {
                Element* dodany = new Element(std::move(a));
                if(rozmiar == 0)
                {
                    dodany->nastepny = dodany;
                    pierwszy = dodany;
                    ostatni = dodany;
                }
                else
                {
                    dodany->nastepny = pierwszy;
                    pierwszy = dodany;
                }
                ++rozmiar;
            }

            void push_front(const T& a)
            {
                Element* dodany = new Element(a);
                if(rozmiar == 0)
                {
                    dodany->nastepny = dodany;
                    pierwszy = dodany;
                    ostatni = dodany;
                }
                else
                {
                    dodany->nastepny = pierwszy;
                    pierwszy = dodany;
                }
                ++rozmiar;
            }

            std::string print()
            {
                std::stringstream lista;
                lista << "Lista(";
                lista << rozmiar;
                lista << "){";
                if(rozmiar != 0) {
                    Element* element = pierwszy;
                    for(unsigned int i=0; i<rozmiar; ++i) {
                        if(i>0)
                            lista << ", ";
                        lista << element->wartosc;
                        element = element->nastepny;
                    }
                }
                lista << "}";
                return lista.str();
            }
    };

    template<typename T>
    void swap(Lista<T>& v1, Lista<T>& v2)
    {
        v1.swap(v2);
    }

    template<typename T>
    bool operator==(const Lista<T> l1, const Lista<T> l2)
    {
        if(l1.size() == l2.size())
        {
            unsigned int it = 0;
            auto t1 = l1.Poczatek();
            auto t2 = l2.Poczatek();
            while(t1->wartosc == t2->wartosc)
            {
                t1 = t1->nastepny;
                t2 = t2->nastepny;
                ++it;
                if(it == l1.size())
                    return true;
            }
        }
        return false;
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
            if(l.size() != 0)
            {
                auto element = l.Poczatek();
                for(unsigned int i=0; i<l.size(); ++i)
                {
                    if(i>0)
                        wyjscie << ", ";
                    wyjscie << element->wartosc;
                    element = element->nastepny;
                }
            }
        wyjscie << "}";
        return wyjscie;
    }
}
void test_lista(void);

#endif // LISTA_HPP_INCLUDED
