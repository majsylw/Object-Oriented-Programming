#ifndef LISTA1_HPP_INCLUDED
#define LISTA1_HPP_INCLUDED

#include<string>
#include<sstream>
#include<cassert>
#include<iostream>

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

#endif // LISTA1_HPP_INCLUDED
