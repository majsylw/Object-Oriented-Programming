#include "IntTab1.h"
#include "IntTab2.h"
#include "IntTab3.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>

/*Przygotuj trzy wersje klasy IntTab z zadania 1 (w takiej wersji, w której można zadeklarować konstruktor przenoszący
i operator przypisania z rvalue jako noexcept):

- wyposażoną zarówno w konstruktor kopiujący i operator przypisania,
jak i w konstruktor przenoszący i operator przypisania z rvalue, oba ostatnie z deklaracją noexcept,

- wyposażoną zarówno w konstruktor kopiujący i operator przypisania,
jak i w konstruktor przenoszący i operator przypisania z rvalue, oba ostatnie bez deklaracji noexcept,

- wyposażoną jedynie w konstruktor kopiujący i operator przypisania
(jak wiemy, konstruktora przenoszącego i operatora przypisania z rvalue kompilator nam sam z siebie
 w tym przypadku nie dodefiniuje).

Zaprojektuj eksperyment, w którym skorzystasz z kolekcji standardowej std::vector do przechowywania obiektów raz jednej,
raz drugiej, a raz trzeciej odmiany IntTab w taki sposób, aby zmusić ją do wielokrotnej wewnętrznej realokacji
(np. dokładając wiele razy po jednym elemencie). Zmierz czasy eksperymentów z poszczególnymi wariantami i porównaj.
Czasy możesz zmierzyć korzystając np. ze wskazówek zawartych tu: http://en.cppreference.com/w/cpp/chrono

Spróbuj również zmienić build target w Code::Blocks z Debug na Release, czyli na taki z włączonymi optymalizacjami kompilatora,
i wtedy popatrzeć na czasy.*/

template<typename T>
double TestCzasu(void)
{
    std::chrono::time_point<std::chrono::system_clock> start, koniec;
    start = std::chrono::system_clock::now();
    std::vector<T> v1;
    for (int i = 1; i <= 20000; ++i)
    {
            v1.push_back(T(i));

    }
    koniec = std::chrono::system_clock::now();
    std::chrono::duration<double> uplynelo = koniec - start;
    //std::chrono::seconds uplynelo = koniec - start; //w c++14 ?
    return uplynelo.count();
}

int main(void)
{
    //std::cout << sizeof(double) << std::endl;

    /*std::cout << "Test dla IntTab3 -> ";
    std::chrono::time_point<std::chrono::system_clock> start, koniec;
    start = std::chrono::system_clock::now();
    std::vector<IntTab3> v1;
    for (int i = 1; i <= 10000; ++i) {
        v1.push_back(IntTab3(i));
    }
    std::vector<IntTab3> v2;
    v2 = std::move(v1);
    koniec = std::chrono::system_clock::now();
    std::chrono::duration<double> uplynelo1 = koniec - start;
    std::cout << uplynelo1.count() << "s" << std::endl;

    std::cout << "Test dla IntTab2 -> ";
    start = std::chrono::system_clock::now();
    std::vector<IntTab2> v3;
    for (int i = 1; i <= 10000; ++i) {
        v3.push_back(IntTab2(i));
    }
    std::vector<IntTab2> v4;
    v4 = std::move(v3);
    koniec = std::chrono::system_clock::now();
    std::chrono::duration<double> uplynelo2 = koniec - start;
    std::cout << uplynelo2.count() << "s" << std::endl;

    std::cout << "Test dla IntTab3 -> ";
    start = std::chrono::system_clock::now();
    std::vector<IntTab1> v5;
    for (int i = 1; i <= 10000; ++i) {
        v5.push_back(IntTab1(i));
    }
    std::vector<IntTab1> v6;
    v6 = std::move(v5);
    koniec = std::chrono::system_clock::now();
    std::chrono::duration<double> uplynelo3 = koniec - start;
    std::cout << uplynelo3.count() << "s" << std::endl;*/

    //konstruktor przenoszacy, operator przypisania z rvalue, z deklaracja noexcept
    std::cout << "Test dla IntTab1 -> " << TestCzasu<IntTab1>() << "s" << std::endl;
    //konstruktor przenoszacy, operator przypisania z rvalue, bez deklaracji noexcept
    std::cout << "Test dla IntTab2 -> " << TestCzasu<IntTab2>() << "s" << std::endl;
    //konstruktor kopiujacy, operator przypisania
    std::cout << "Test dla IntTab3 -> " << TestCzasu<IntTab3>() << "s" << std::endl;

    /*Wyniki dla 20000 iteracji:
    1)Debug:
    IntTab1: 1,6911s
    IntTab2: 1,18807s
    IntTab3: 10,6826s

    2)Release:
    IntTab1: 1,22807s
    IntTab2: 1,16807s
    IntTab3: 10,4396s
    */

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}

