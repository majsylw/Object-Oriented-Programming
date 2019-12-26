#include "Karta.hpp"
#include <iostream>

/*Napisz klas� Karta, wst�pnie om�wion� na wyk�adzie, kt�rej obiekty b�d� reprezentowa�y numery kart p�atniczych.
Wyposa� j� w konstruktor z argumentem typu std::string, kt�ry b�dzie akceptowa� numery kart w postaci 16 cyfr,
kt�re mog� by� porozdzielane spacjami.

Podobnie jak w zadaniu powy�ej, wyposa� klas� Karta, w klasy wyj�tk�w odpowiadaj�cych sytuacji przekazania konstruktorowi napisu,
w kt�rym s� inne znaki ni� cyfry i whitespace, oraz sytuacji, w kt�rej przekazany numer ma z pozoru poprawny format,
ale nie przechodzi testu sumy kontrolnej (algorytm Luhna musi da� zero, poszukaj jego definicji).

Wyposa� obiekty wyj�tk�w w pola umo�liwiaj�ce przekazanie cho� cz�ci informacji o b��dnie przekazanych danych.
Poniewa� nie powinni�my definiowa� atrybutu typu std::string w wyj�tkach, musimy go zast�pi� atrybutem-tablic� o sta�ym rozmiarze,
np. char wrong_[40];, gdzie 40 jest ustalonym w czasie kompilacji rozmiarem bufora (mog� pa�stwo wybra� inny rozmiar,
je�eli b�dzie bardziej sensowny). Aby taki atrybut wykorzysta�, musz� pa�stwo przekopiowa� do niego litery,
i zako�czy� liter� o numerze zero, kt�ra informuje system, �e napis si� ju� ko�czy (cho� tablica by� mo�e jeszcze nie).
Atrybut wrong_, jako tablica, jest typu char*, i mo�na go np. bezpo�rednio wypisa� na strumie�, albo zamieni� na std::string
ju� w klauzuli catch. Do kopiowania liter mo�na u�y� funkcji z biblioteki cstring oraz metody c_str obiekt�w std::string.
Uwaga: nie nale�y kopiowa� wi�cej liter ni� zmie�ci si� w tablicy (razem z ko�cow� liter� o numerze zero).
W przeciwnym razie b�dziemy mieli do czynienia z b��dem przepe�nienia bufora, jedn� z najgro�niejszych luk bezpiecze�stwa.*/


int main()
{
    test_Karty();

    return 0;
}
