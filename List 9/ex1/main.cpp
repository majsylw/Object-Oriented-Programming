#include <iostream>

#include "Ksiazka.hpp"
#include "Film.hpp"
#include "Osoba.hpp"
#include "Firma.hpp"
#include "Biblioteka.hpp"

int main( void )
{
    Biblioteka * biblioteka = new Biblioteka;

    int ksiazka1 = biblioteka->dodajRzecz( new Ksiazka( "Analiza numeryczna", "David Kincaid" ) );
    int ksiazka2 = biblioteka->dodajRzecz( new Ksiazka( "Wstep do Matematyki", "Jan Kraszewski" ) );
    int film1 = biblioteka->dodajRzecz( new Film( "Hiperbolled", "Jan Dymara", "studenci UWr" ) );
    int film2 = biblioteka->dodajRzecz( new Film( "Swiat Algebry", "Ludomir Newelski", "studenci UWr" ) );

    int klient1 = biblioteka->dodajKlienta( new Osoba( "Jan", "Nowak" ) );
    int klient2 = biblioteka->dodajKlienta( new Firma( "Firma A" ) );

    int klient3;
    {
        Osoba * ktos = new Osoba( "Kazimierz", "Wielki" );
        klient3 = biblioteka->dodajKlienta( ktos );
    }

    int wypozyczenie1 = biblioteka->noweWypozyczenie( klient2, ksiazka2 );
    int wypozyczenie2 = biblioteka->noweWypozyczenie( klient2, ksiazka1 );
    int wypozyczenie3 = biblioteka->noweWypozyczenie( klient1, ksiazka1 );
    int wypozyczenie4 = biblioteka->noweWypozyczenie( klient1, film2 );

    int zwrot1 = biblioteka->zwrotWypozyczenia( wypozyczenie2 );

    std::cout << "Wszystkie wypozyczone rzeczy:" << std::endl;
    for( auto i : biblioteka->wypozyczoneRzeczy() ) {
        std::cout << i << std::endl;
    }

    std::cout << "Wypozyczone rzeczy klienta2:" << std::endl;
    for( auto i : biblioteka->wypozyczoneRzeczy( klient2 ) ) {
        std::cout << i << std::endl;
    }

    std::cout << "Rzeczy:" << std::endl;
    std::cout << ksiazka1 << std::endl;
    std::cout << ksiazka2 << std::endl;
    std::cout << film1 << std::endl;
    std::cout << film2 << std::endl;

    std::cout << "Klienci:" << std::endl;
    std::cout << klient1 << std::endl;
    std::cout << klient2 << std::endl;
    std::cout << klient3 << std::endl;

    std::cout << "Wypozyczenia:" << std::endl;
    std::cout << wypozyczenie1 << std::endl;
    std::cout << wypozyczenie2 << std::endl;
    std::cout << wypozyczenie3 << std::endl;
    std::cout << wypozyczenie4 << std::endl;

    std::cout << "Zwroty:" << std::endl;
    std::cout << zwrot1 << std::endl;

    delete biblioteka;

    std::cin.get();
    return 0;
}
