#include <iostream>
#include "Ryzyko.hpp"

/*Ryzyko (�argonowy odpowiednik s�owa polisa) motoryzacyjne pewnej firmy dzieli si� na podryzyka,
dla kt�rych osobno oblicza si� sk�adk�, i potem sumuje, aby otrzyma� sk�adk� za ca�� polis�. I tak:
-dla podryzyka po�aru sk�adk� oblicza si� jako 1% warto�ci pojazdu,
-dla podryzyka wypadku sk�adk� dla kierowcy w wieku 18-25 oblicza si� jako 20% warto�ci pojazdu pomniejszonej
 o indywidualnie kwotowo ustalony udzia� w�asny w�a�ciciela a dla kierowcy w wieku 26 i wi�cej lat jako 10% warto�ci
 pojazdu pomniejszonej o indywidualnie kwotowo ustalony udzia� w�asny w�a�ciciela,
-dla podryzyka szkody z przyczyn naturalnych, np. gradu jako 2% warto�ci pojazdu,
-dla podryzyka odpowiedzialno�ci cywilnej na mieniu 0.03% ustawowej kwoty gwarancyjnej obowi�zuj�cej
 w chwili zawarcia umowy (prosz� sprawdzi� jaka jest w bie��cym roku) obni�ona o indywidualny procentowy rabat klienta.
Klient kupuj�c polis� decyduje kt�re opcje wybiera.*/

void symulacja(void)
{
  Ryzyko polisa1(245500.0, 21, 100000.0, 7, "AUDI");

  polisa1.DodajPodryzyko("szkoda_naturalna");
  polisa1.DodajPodryzyko("wypadek");
  polisa1.DodajPodryzyko("pozar");
  polisa1.DodajPodryzyko("OC");

  polisa1.DodajPodryzyko("wypadek");

  polisa1.WypiszUbezpieczenia();
  std::cout << "Ogolna stawka: " << polisa1.Polisa() << std::endl;

  polisa1.UsunPodryzyko("pozar");
  polisa1.WypiszUbezpieczenia();

  polisa1.UsunPodryzyko("pozar");

  std::cout << "Ogolna stawka: " << polisa1.Polisa() << std::endl;
}

int main(void)
{
  symulacja();

  return 0;
}
