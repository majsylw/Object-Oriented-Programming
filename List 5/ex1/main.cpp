#include <iostream>
#include "HeapOptional.hpp"
#include "Data.hpp"

/*
Uzupelnij wzorzec HeapOptional z wykladu o tworzenie glebokich kopii w konstruktorze kopiuj�cym oraz w operatorze przypisania,
przy upraszczajacym zalozeniu, ze obiekty, kt�rych wlascicielami jestesmy, sa takiego samego typu, jak ten uzyty do stworzenia
instancji wzorca, a nie jakiegos typu pochodnego. Napisz funkcj� testujaca mozliwie duzo zaprogramowanych uslug.
Spr�buj przetestowac r�wniez, czy obiekty podrzedne, kt�rch obiekty HeapOptional sa wlascicielami, sa faktycznie kasowane
w stosownych momentach. Mozesz w tym celu potrzebowac osobnej, specjalnie wyposazonej klasy dla obiekt�w podrz�dnych.
*/

int main()
{
    testy();

    std::cin.get();

    return 0;
}
