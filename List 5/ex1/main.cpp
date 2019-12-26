#include <iostream>
#include "HeapOptional.hpp"
#include "Data.hpp"

/*
Uzupelnij wzorzec HeapOptional z wykladu o tworzenie glebokich kopii w konstruktorze kopiuj¹cym oraz w operatorze przypisania,
przy upraszczajacym zalozeniu, ze obiekty, których wlascicielami jestesmy, sa takiego samego typu, jak ten uzyty do stworzenia
instancji wzorca, a nie jakiegos typu pochodnego. Napisz funkcjê testujaca mozliwie duzo zaprogramowanych uslug.
Spróbuj przetestowac równiez, czy obiekty podrzedne, którch obiekty HeapOptional sa wlascicielami, sa faktycznie kasowane
w stosownych momentach. Mozesz w tym celu potrzebowac osobnej, specjalnie wyposazonej klasy dla obiektów podrzêdnych.
*/

int main()
{
    testy();

    std::cin.get();

    return 0;
}
