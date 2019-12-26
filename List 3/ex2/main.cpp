#include "Data.hpp"
#include <iostream>


/*Wyposa� konstruktor klasy Data w obs�ug� b��dnych argument�w poprzez wyj�tki. Zr�b to w taki spos�b,
aby by� w stanie w kodzie klienckim stwierdzi� jaka kategoria b��du nast�pi�a (z�y rok, np. 0,
z�y miesi�c, spoza 1-12, z�y dzie� w danym miesi�cu). Napisz operator wej�cia operator>> dla typu Data,
w kt�rym nie b�dziesz sprawdza� czy wczytane trzy liczby typu int maj� sensowne warto�ci, tylko wywo�asz z nimi konstruktor Data,
kt�ry zajmie si� sprawdzaniem. Napisz funkcj� testuj�c� wszystkie te us�ugi, ze sprawdzeniem, czy w okre�lonych sytuacjach wyj�tki
rzeczywi�cie s� zg�aszane. Wszystko, jak zwykle, umie�� w stosownych plikach.

Napisz aplikacj�, w kt�rej skorzystasz z powy�szego operatora wej�cia (np. wczytasz dat� ze strumienia i wypiszesz,
czy by�a ona prawid�owa czy nie). Zauwa�, �e masz teraz dwa rodzaje b��d�w, r�nie obs�ugiwanych. Je�eli nie uda�o si� wczyta�
trzech liczb, strumie� b�dzie zepsuty. Je�eli si� uda�o, ale nie spe�niaj� one kryteri�w, b�dzie zg�oszony wyj�tek.
Spr�buj przeczyta� w dokumentacji, jak mo�na nam�wi� strumie� �eby zg�asza� wyj�tek r�wnie� w pierwszym scenariuszu
(np. tu: http://en.cppreference.com/w/cpp/io/basic_ios/exceptions). Spr�buj przestawi� stan strumienia w taki spos�b,
aby w ka�dej sytuacji odtworzy� stan uprzedni. Omawiali�my jak to mo�na zrobi� w zesz�ym semestrze, jeden ze scenariuszy jest
opisany np. tu: http://ljwo.wordpress.com/2014/05/14/stdios_base-format-flags-are-a-resource-that-needs-raii/
(tzn. w tym artykule jest opisana technika, kt�r� nale�y zaadaptowa� do flag strumienia opisuj�cych zg�aszane wyj�tki,
 o kt�rych jest mowa w dokumentacji basic_ios/exceptions powy�ej).*/

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
