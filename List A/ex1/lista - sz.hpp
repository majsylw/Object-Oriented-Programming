#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include<string>
#include<sstream>
#include<cassert>
#include<iostream>

template<class T>
class Lista
{
    private:
        struct Element
        {
				Element* nastepny;
				//Element* poprzedni;
				T wartosc;
				Element() {
					wartosc = 0;
				}
				Element(T val) {
					wartosc = val;
				}
		};

		unsigned int rozmiar;
		//Element* iterator;
		Element* pierwszy;
		Element* ostatni;

	public:
		Lista()
		{
			rozmiar = 0;
		}

		Lista(const Lista& v)
        {
            if(v.rozmiar > 0)
            {
                Element* tymczasowy = v.pierwszy;

                while(tymczasowy->nastepny != v.pierwszy)
                {
                    push_back(tymczasowy->wartosc);
                    tymczasowy = tymczasowy->nastepny;
                }
                push_back(ostatni->wartosc);
            }
            rozmiar = v.rozmiar;
        }

        Lista& operator=(Lista& v)
        {
            Lista k(v);
            swap(k);
            return *this;
        }

        //Konstrutor przenoszacy, operator przypisania  r-value

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

        void resize (unsigned int n, const T& val = 0)
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
				//dodany->poprzedni = dodany;
				dodany->nastepny = dodany;
				//iterator = dodany;
				pierwszy = dodany;
				ostatni = dodany;
			}
			else
			{
				ostatni->nastepny = dodany;
				//dodany->poprzedni = ostatni;
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
				//dodany->poprzedni = dodany;
				dodany->nastepny = dodany;
				//iterator = dodany;
				pierwszy = dodany;
				ostatni = dodany;
			}
			else
			{
				ostatni->nastepny = dodany;
				//dodany->poprzedni = ostatni;
				dodany->nastepny = pierwszy;
				ostatni = dodany;
			}
			++rozmiar;
        }

        void pop_back()
        {
            //assert(rozmiar > 0);

            Element* tymczasowy = pierwszy;
            delete ostatni;
            while( tymczasowy->nastepny != ostatni )
            {
                tymczasowy = tymczasowy->nastepny;
            }
            tymczasowy->nastepny = pierwszy;
			ostatni = tymczasowy;
			--rozmiar;
		}

        void push_front(T&& a)
        {
            Element* dodany = new Element(std::move(a));
			if(rozmiar == 0)
            {
				//dodany->poprzedni = dodany;
				dodany->nastepny = dodany;
				//iterator = dodany;
				pierwszy = dodany;
				ostatni = dodany;
			}
			else
            {
				//dodany->poprzedni = ostatni;
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
				//dodany->poprzedni = dodany;
				dodany->nastepny = dodany;
				//iterator = dodany;
				pierwszy = dodany;
				ostatni = dodany;
			}
			else
            {
				//dodany->poprzedni = ostatni;
				dodany->nastepny = pierwszy;
				pierwszy = dodany;
			}
			++rozmiar;
        }

		/*int get() {
			return iterator->wartosc;
		}
		int get(int index) {
			if(rozmiar == 0 || index > rozmiar || index < 1)
				return -1;
			--index;
			Element * tmp = pierwszy;
			for(int i=0; i<index; ++i) {
				tmp = tmp->nastepny;
			}
			iterator = tmp;
			return tmp->wartosc;
		}
		int find(int wartosc) {
			int index = -1;
			Element * tmp = pierwszy;
			for(int i=0; i<rozmiar; ++i) {
				if(tmp->wartosc == wartosc) {
					index = ++i;
					break;
				}
				tmp = tmp->nastepny;
			}
			iterator = tmp;
			return index;
		}
		int begin() {
			iterator = pierwszy;
			return 0;
		}
		int nastepny() {
			iterator = iterator->nastepny;
			return 0;
		}
		int end() {
			iterator = ostatni;
			return 0;
		}
		int max() {
			if(rozmiar == 0)
				return -1;
			iterator = pierwszy;
			Element * max = iterator;
			int i = 0;
			while(i < rozmiar) {
				iterator = iterator->nastepny;
				if(max->wartosc < iterator->wartosc) {
					max = iterator;
				}
				++i;
			}
			iterator = max;
			return 0;
		}
		int min() {
			if(rozmiar == 0)
				return -1;
			iterator = pierwszy;
			Element * min = iterator;
			int i = 0;
			while(i < rozmiar) {
				iterator = iterator->nastepny;
				if(min->wartosc > iterator->wartosc) {
					min = iterator;
				}
				++i;
			}
			iterator = min;
			return 0;
		}
		Element * iterate() {
			return iterator;
		}
		int poprzedni() {
			iterator = iterator->poprzedni;
			return 0;
		}*/
		std::string print() {
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
			lista << "}\n";
			return lista.str();
		}
};

template<typename T>
void swap(Lista<T>& v1, Lista<T>& v2)
{
    v1.swap(v2);
}

void test_lista(void);


#endif // LISTA_HPP_INCLUDED
