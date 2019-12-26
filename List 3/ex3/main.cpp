#include "Wymierna.hpp"
#include "nwd.hpp"

#include <iostream>
#include <cassert>

/*Przer�b funkcj� licz�c� najwi�kszy wsp�lny dzielnik dla dw�ch liczb typu int,
omawian� w zesz�ym semestrze, na wzorzec funkcji licz�cej najwi�kszy wsp�lny dzielnik
dla dw�ch liczb dowolnego ale tego samego typu (od kt�rego wymagamy oczywi�cie stosownych
operacji arytmetycznych u�ywanych w obliczeniach). Do wzorca do��cz funkcj� testuj�c� go
dla konkretnych danych konkretnego typu (np. int). Umie�� ten wzorzec i funkcj� testuj�c�
w stosownym pliku/plikach. Napisz klas� Wymierna, kt�ra b�dzie reprezentowa� liczb� wymiern�.
Zaimplementuj j� tak, �eby przechowywa�a ju� skr�cone licznik i mianownik jako atrybuty prywatne typu long.
Konstruktor napisz jako zwyk�� metod�, a akcesory licznika i mianownika napisz jako metody inline.
W tym zadaniu warunki sensowno�ci w konstruktorze wymuszaj przez assert. Nie rozbudowuj tej klasy ponad potrzeb�,
omawia� b�dziemy tylko to, o czym jest jawnie mowa w tym poleceniu. Napisz r�wnie� funkcj� testuj�c� us�ugi tej klasy,
a wszystko umie�� w stosownych plikach. Napisz aplikacj�, kt�ra co najmniej wywo�a testy dla reszty kodu.*/


int main()
{
    test_Wymierna();
    test_NWDtemplate();

    return 0;
}
