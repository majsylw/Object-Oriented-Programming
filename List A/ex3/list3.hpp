#ifndef LIST3_HPP_INCLUDED
#define LIST3_HPP_INCLUDED

#include<string>
#include<sstream>
#include<cassert>
#include<iostream>

namespace maj {

    template<class T>
    class Lista
    {
        private:
            struct Element
            {
                Element* nastepny;
                Element* poprzedni;
                T wartosc;

                Element();
                Element(T val);
            };

            unsigned int rozmiar;
            Element * pierwszy;

            template<typename TT>
            friend std::ostream& operator<<(std::ostream&, Lista<TT>);

            template<typename TT>
            friend bool operator==(const Lista<TT>, const Lista<TT>);

        public:
            Lista( );
            Lista( const Lista& );
            Lista& operator=( const Lista& );
            Lista( Lista&& );
            Lista& operator=( Lista&& ) noexcept;
            ~Lista( );
            bool empty( void ) const;
            int size( ) const;
            Element * Poczatek( ) const;
            void resize( unsigned int, const T& val = T() );
            void swap( Lista& ) noexcept;
            void push_back( T&& );
            void push_back( const T& );
            void pop_back( );
            void push_front( T&& );
            void push_front( const T& );
            std::string print( );

            class Iterator : public std::iterator<std::bidirectional_iterator_tag,T>
            {
                private:
                    Element* aktualny;
                    Lista<T>* lista;

                public:
                    Iterator(Element* el = nullptr, Lista<T>* lista = nullptr);
                    ~Iterator();
                    Element* Aktualny() const;
                    Iterator& operator++();
                    Iterator operator++(int);
                    Iterator& operator--();
                    Iterator operator--(int);
                    T* operator->() const;
                    T* operator->();
                    T operator*() const;
                    T operator*();
                    bool operator==(Iterator);
                    bool operator!=(Iterator);
            };

            typedef const Iterator const_iterator;

            Iterator begin();
            const_iterator begin() const;

            Iterator end();
            const_iterator end() const;

            void erase(const_iterator iter);
    };

    template<typename T>
    void swap( Lista<T>&, Lista<T>& );

    template<typename T>
    bool operator==( const Lista<T>, const Lista<T> );

    template<typename T>
    bool operator!=( const Lista<T>, const Lista<T> );

    template<typename T>
    std::ostream& operator<<( std::ostream&, Lista<T> );
}

void test_lista(void);

#endif // LIST3_HPP_INCLUDED
