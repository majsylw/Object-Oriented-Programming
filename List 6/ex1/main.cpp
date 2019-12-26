#include "IntTab.hpp"
#include <iostream>

/*Napisz klasê IntTab, która bêdzie zarz¹dzaæ tablic¹ liczb typu int, o rozmiarze podanym w konstruktorze.
Podstawowy konstruktor tej klasy ma sam podj¹æ próbê zaalokowania tablicy, a destruktor jej zwolnienia.
Nie korzystamy w tym zadaniu ani z TabOptional ani z unique_ptr. Poza konstruktorem i destruktorem wyposa¿ klasê równie¿ w:
- metodê size, która zwróci rozmiar wewnêtrznie przechowywanej tablicy,
- konstruktor kopiuj¹cy oraz operator przypisania zgodne ze strategi¹ g³êbokiej kopii
- medotê swap pozwalaj¹c¹ na wymianê zawartoœci dwóch obiektów typu IntTab
- dwa operatory [], const oraz nie-const, które pozwol¹ na odczyt i zapis wartoœci pod okreœlonymi indeksami tablicy.*/

int main(void)
{
    test_IntTab();

    return 0;
}
