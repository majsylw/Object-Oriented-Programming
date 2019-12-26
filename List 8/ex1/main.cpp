#include "Dzialalnosc_gospodarcza.hpp"

/*Spr�buj zastanowi� si�, jak zmieni� struktur� programu, kt�ry pojawi� si� na wyk�adzie, tak aby unikn�� zbiegania si�
r�nych �cie�ek dziedziczenia na wsp�lnej klasie bazowej. Dla przypomnienia, mieli�my
-klas� bazow� Podatnik, kt�ra przetwarza�a numery nip oraz mia�a wirtualny destruktor i wirtualn� metod� wizytowka
 pozwalaj�c� na wypisanie danych podatnika,
-klas� pochodn� OsobaFizyczna, kt�ra dziedziczy�a publicznie po klasie Podatnik i przetwarza�a imi� i nazwisko,
 i przedefiniowywa�a (w sensie override) metod� wizytowka,
-klas� pochodn� Firma, kt�ra dziedziczy�a publicznie po klasie Podatnik i przetwarza�a numer regon,
 i przedefiniowywa�a (w sensie override) metod� wizytowka,
-klas� pochodn� Dzialalnosc, kt�ra dziedziczy�a publicznie po klasie OsobaFizyczna oraz po klasie Firma,
 i przedefiniowywa�a (w sensie override) metod� wizytowka.
Klasa Dzialalnosc zawiera dwa potencjalnie r�ne obiekty typu Podatnik, co jest sporym k�opotem.
Zaproponuj jakie� wyj�cie z sytuacji. Przeprojektuj hierarchi�, nie u�ywaj dziedziczenia wirtualnego.
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
