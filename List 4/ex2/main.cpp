#include "Karta.hpp"
#include <iostream>

/*Napisz klasê Karta, wstêpnie omówion¹ na wyk³adzie, której obiekty bêd¹ reprezentowa³y numery kart p³atniczych.
Wyposa¿ j¹ w konstruktor z argumentem typu std::string, który bêdzie akceptowa³ numery kart w postaci 16 cyfr,
które mog¹ byæ porozdzielane spacjami.

Podobnie jak w zadaniu powy¿ej, wyposa¿ klasê Karta, w klasy wyj¹tków odpowiadaj¹cych sytuacji przekazania konstruktorowi napisu,
w którym s¹ inne znaki ni¿ cyfry i whitespace, oraz sytuacji, w której przekazany numer ma z pozoru poprawny format,
ale nie przechodzi testu sumy kontrolnej (algorytm Luhna musi daæ zero, poszukaj jego definicji).

Wyposa¿ obiekty wyj¹tków w pola umo¿liwiaj¹ce przekazanie choæ czêœci informacji o b³êdnie przekazanych danych.
Poniewa¿ nie powinniœmy definiowaæ atrybutu typu std::string w wyj¹tkach, musimy go zast¹piæ atrybutem-tablic¹ o sta³ym rozmiarze,
np. char wrong_[40];, gdzie 40 jest ustalonym w czasie kompilacji rozmiarem bufora (mog¹ pañstwo wybraæ inny rozmiar,
je¿eli bêdzie bardziej sensowny). Aby taki atrybut wykorzystaæ, musz¹ pañstwo przekopiowaæ do niego litery,
i zakoñczyæ liter¹ o numerze zero, która informuje system, ¿e napis siê ju¿ koñczy (choæ tablica byæ mo¿e jeszcze nie).
Atrybut wrong_, jako tablica, jest typu char*, i mo¿na go np. bezpoœrednio wypisaæ na strumieñ, albo zamieniæ na std::string
ju¿ w klauzuli catch. Do kopiowania liter mo¿na u¿yæ funkcji z biblioteki cstring oraz metody c_str obiektów std::string.
Uwaga: nie nale¿y kopiowaæ wiêcej liter ni¿ zmieœci siê w tablicy (razem z koñcow¹ liter¹ o numerze zero).
W przeciwnym razie bêdziemy mieli do czynienia z b³êdem przepe³nienia bufora, jedn¹ z najgroŸniejszych luk bezpieczeñstwa.*/


int main()
{
    test_Karty();

    return 0;
}
