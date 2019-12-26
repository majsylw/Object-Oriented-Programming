#include "TableOptional.hpp"
#include <iostream>

/*
Na wykladzie widzielismy oprogramowany wzorzec klasy HeapOptional, kt�ry zarzadzal czasem zycia pojedynczego obiektu,
kt�ry tworzylismy na stercie, i do kt�rego wskaznik przekazywali�my mu w konstruktorze. Z powodu problemu plytkich kopii
calkowicie wylaczylismy mu r�wniez mozliwosc kopiowania i przypisywania. Pozostajac przy tych ograniczeniach, zaprogramuj
inny wzorzec, nazwij go np. TableOptional, kt�rego obiekty beda zarzadzaly czasem zycia tablicy element�w pewnego typu,
zaalokowanej na stercie, do kt�rej wskaznik przeka�emy im w konstruktorze. Oczywi�cie, w tym przypadku operatory * oraz ->
nie bardzo maja sens, ale przydalby si� operator []. Napisz funkcj� testujace mozliwie du�o zaprogramowanych uslug.
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
