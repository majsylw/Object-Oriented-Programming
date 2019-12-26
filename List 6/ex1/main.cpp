#include "IntTab.hpp"
#include <iostream>

/*Napisz klas� IntTab, kt�ra b�dzie zarz�dza� tablic� liczb typu int, o rozmiarze podanym w konstruktorze.
Podstawowy konstruktor tej klasy ma sam podj�� pr�b� zaalokowania tablicy, a destruktor jej zwolnienia.
Nie korzystamy w tym zadaniu ani z TabOptional ani z unique_ptr. Poza konstruktorem i destruktorem wyposa� klas� r�wnie� w:
- metod� size, kt�ra zwr�ci rozmiar wewn�trznie przechowywanej tablicy,
- konstruktor kopiuj�cy oraz operator przypisania zgodne ze strategi� g��bokiej kopii
- medot� swap pozwalaj�c� na wymian� zawarto�ci dw�ch obiekt�w typu IntTab
- dwa operatory [], const oraz nie-const, kt�re pozwol� na odczyt i zapis warto�ci pod okre�lonymi indeksami tablicy.*/

int main(void)
{
    test_IntTab();

    return 0;
}
