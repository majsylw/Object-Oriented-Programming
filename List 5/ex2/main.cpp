#include "TableOptional.hpp"
#include <iostream>

/*
Na wykladzie widzielismy oprogramowany wzorzec klasy HeapOptional, który zarzadzal czasem zycia pojedynczego obiektu,
który tworzylismy na stercie, i do którego wskaznik przekazywaliœmy mu w konstruktorze. Z powodu problemu plytkich kopii
calkowicie wylaczylismy mu równiez mozliwosc kopiowania i przypisywania. Pozostajac przy tych ograniczeniach, zaprogramuj
inny wzorzec, nazwij go np. TableOptional, którego obiekty beda zarzadzaly czasem zycia tablicy elementów pewnego typu,
zaalokowanej na stercie, do której wskaznik przeka¿emy im w konstruktorze. Oczywiœcie, w tym przypadku operatory * oraz ->
nie bardzo maja sens, ale przydalby siê operator []. Napisz funkcjê testujace mozliwie du¿o zaprogramowanych uslug.
Czego nie udalo Ci sie sprawdzic w funkcji testujacej?
*/

int main()
{
    testy_TableOptional();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();

    return 0;
}
