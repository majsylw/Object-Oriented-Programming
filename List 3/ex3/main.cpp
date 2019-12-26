#include "Wymierna.hpp"
#include "nwd.hpp"

#include <iostream>
#include <cassert>

/*Przerób funkcjê licz¹c¹ najwiêkszy wspólny dzielnik dla dwóch liczb typu int,
omawian¹ w zesz³ym semestrze, na wzorzec funkcji licz¹cej najwiêkszy wspólny dzielnik
dla dwóch liczb dowolnego ale tego samego typu (od którego wymagamy oczywiœcie stosownych
operacji arytmetycznych u¿ywanych w obliczeniach). Do wzorca do³¹cz funkcjê testuj¹c¹ go
dla konkretnych danych konkretnego typu (np. int). Umieœæ ten wzorzec i funkcjê testuj¹c¹
w stosownym pliku/plikach. Napisz klasê Wymierna, która bêdzie reprezentowaæ liczbê wymiern¹.
Zaimplementuj j¹ tak, ¿eby przechowywa³a ju¿ skrócone licznik i mianownik jako atrybuty prywatne typu long.
Konstruktor napisz jako zwyk³¹ metodê, a akcesory licznika i mianownika napisz jako metody inline.
W tym zadaniu warunki sensownoœci w konstruktorze wymuszaj przez assert. Nie rozbudowuj tej klasy ponad potrzebê,
omawiaæ bêdziemy tylko to, o czym jest jawnie mowa w tym poleceniu. Napisz równie¿ funkcjê testuj¹c¹ us³ugi tej klasy,
a wszystko umieœæ w stosownych plikach. Napisz aplikacjê, która co najmniej wywo³a testy dla reszty kodu.*/


int main()
{
    test_Wymierna();
    test_NWDtemplate();

    return 0;
}
