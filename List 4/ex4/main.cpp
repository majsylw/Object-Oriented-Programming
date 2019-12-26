#include <iostream>
#include "Ryzyko.hpp"

/*Ryzyko (¿argonowy odpowiednik s³owa polisa) motoryzacyjne pewnej firmy dzieli siê na podryzyka,
dla których osobno oblicza siê sk³adkê, i potem sumuje, aby otrzymaæ sk³adkê za ca³¹ polisê. I tak:
-dla podryzyka po¿aru sk³adkê oblicza siê jako 1% wartoœci pojazdu,
-dla podryzyka wypadku sk³adkê dla kierowcy w wieku 18-25 oblicza siê jako 20% wartoœci pojazdu pomniejszonej
 o indywidualnie kwotowo ustalony udzia³ w³asny w³aœciciela a dla kierowcy w wieku 26 i wiêcej lat jako 10% wartoœci
 pojazdu pomniejszonej o indywidualnie kwotowo ustalony udzia³ w³asny w³aœciciela,
-dla podryzyka szkody z przyczyn naturalnych, np. gradu jako 2% wartoœci pojazdu,
-dla podryzyka odpowiedzialnoœci cywilnej na mieniu 0.03% ustawowej kwoty gwarancyjnej obowi¹zuj¹cej
 w chwili zawarcia umowy (proszê sprawdziæ jaka jest w bie¿¹cym roku) obni¿ona o indywidualny procentowy rabat klienta.
Klient kupuj¹c polisê decyduje które opcje wybiera.*/

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
