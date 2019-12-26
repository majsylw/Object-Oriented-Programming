#include "Data.hpp"
#include <iostream>


/*Wyposa¿ konstruktor klasy Data w obs³ugê b³êdnych argumentów poprzez wyj¹tki. Zrób to w taki sposób,
aby byæ w stanie w kodzie klienckim stwierdziæ jaka kategoria b³êdu nast¹pi³a (z³y rok, np. 0,
z³y miesi¹c, spoza 1-12, z³y dzieñ w danym miesi¹cu). Napisz operator wejœcia operator>> dla typu Data,
w którym nie bêdziesz sprawdzaæ czy wczytane trzy liczby typu int maj¹ sensowne wartoœci, tylko wywo³asz z nimi konstruktor Data,
który zajmie siê sprawdzaniem. Napisz funkcjê testuj¹c¹ wszystkie te us³ugi, ze sprawdzeniem, czy w okreœlonych sytuacjach wyj¹tki
rzeczywiœcie s¹ zg³aszane. Wszystko, jak zwykle, umieœæ w stosownych plikach.

Napisz aplikacjê, w której skorzystasz z powy¿szego operatora wejœcia (np. wczytasz datê ze strumienia i wypiszesz,
czy by³a ona prawid³owa czy nie). Zauwa¿, ¿e masz teraz dwa rodzaje b³êdów, ró¿nie obs³ugiwanych. Je¿eli nie uda³o siê wczytaæ
trzech liczb, strumieñ bêdzie zepsuty. Je¿eli siê uda³o, ale nie spe³niaj¹ one kryteriów, bêdzie zg³oszony wyj¹tek.
Spróbuj przeczytaæ w dokumentacji, jak mo¿na namówiæ strumieñ ¿eby zg³asza³ wyj¹tek równie¿ w pierwszym scenariuszu
(np. tu: http://en.cppreference.com/w/cpp/io/basic_ios/exceptions). Spróbuj przestawiæ stan strumienia w taki sposób,
aby w ka¿dej sytuacji odtworzyæ stan uprzedni. Omawialiœmy jak to mo¿na zrobiæ w zesz³ym semestrze, jeden ze scenariuszy jest
opisany np. tu: http://ljwo.wordpress.com/2014/05/14/stdios_base-format-flags-are-a-resource-that-needs-raii/
(tzn. w tym artykule jest opisana technika, któr¹ nale¿y zaadaptowaæ do flag strumienia opisuj¹cych zg³aszane wyj¹tki,
 o których jest mowa w dokumentacji basic_ios/exceptions powy¿ej).*/

int main()
{
    test_Daty();

    Data d(1999,1,1);

    std::cout << "Podaj date." << std::endl;
    std::cin >> d;
    std::cout << "Poprawnie wpisales date. Do widzenia. \n";


    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
