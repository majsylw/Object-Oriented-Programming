#include "Dzialalnosc_gospodarcza.hpp"

/*Spróbuj zastanowiæ siê, jak zmieniæ strukturê programu, który pojawi³ siê na wyk³adzie, tak aby unikn¹æ zbiegania siê
ró¿nych œcie¿ek dziedziczenia na wspólnej klasie bazowej. Dla przypomnienia, mieliœmy
-klasê bazow¹ Podatnik, która przetwarza³a numery nip oraz mia³a wirtualny destruktor i wirtualn¹ metodê wizytowka
 pozwalaj¹c¹ na wypisanie danych podatnika,
-klasê pochodn¹ OsobaFizyczna, która dziedziczy³a publicznie po klasie Podatnik i przetwarza³a imiê i nazwisko,
 i przedefiniowywa³a (w sensie override) metodê wizytowka,
-klasê pochodn¹ Firma, która dziedziczy³a publicznie po klasie Podatnik i przetwarza³a numer regon,
 i przedefiniowywa³a (w sensie override) metodê wizytowka,
-klasê pochodn¹ Dzialalnosc, która dziedziczy³a publicznie po klasie OsobaFizyczna oraz po klasie Firma,
 i przedefiniowywa³a (w sensie override) metodê wizytowka.
Klasa Dzialalnosc zawiera dwa potencjalnie ró¿ne obiekty typu Podatnik, co jest sporym k³opotem.
Zaproponuj jakieœ wyjœcie z sytuacji. Przeprojektuj hierarchiê, nie u¿ywaj dziedziczenia wirtualnego.
*/
#include <iostream>

int main(void)
{
    IndywidualnaDzialalnosc os("2234547112", "Stanislaw", "Wokulski", "123456785");
    os.wizytowka();
    std::cout << std::endl;
    Firma firm("Thyssenkrupp Energostal", "1234567819", "343451285");
    firm.wizytowka();

    return 0;
}
