#include "Vector.hpp"

/*Zaprojektuj i zaprogramuj wzorzec klasy Vector. Obiekty tej klasy bêd¹ przechowywa³y obiekty zadanego typu,
w sposób zbli¿ony do std::vector, choæ z pewnymi ró¿nicami. Biblioteczny typ std::vector rezerwuje miejsce na stercie na zapas,
na obiekty, które dopiero w³o¿ymy do kolekcji (np. przez push_back albo insert), poza tym, w momencie usuwania obiektów
z kolekcji (np. przez pop_back) nie zmniejsza wewnêtrznych danych, tylko traktuje miejsce po usuniêtych jako rezerwê.
Nasza klasa Vector powinna siê zachowywaæ inaczej: rozmiar wewnêtrznej tablicy powinien dok³adnie odpowiadaæ iloœci danych
w ka¿dej chwili (z uwzglêdnieniem szczególnego stanu pustego). Do zarz¹dzania czasem ¿ycia wewnêtrznej tablicy nale¿y u¿yæ
atrybutu typu std::unique_ptr. Wyposa¿ klasê w nastêpuj¹ce operacje:
- konstruktor domyœlny, tworz¹cy pust¹ kolekcjê
- konstruktor z liczby ca³kowitej n ze znakiem tworz¹cy kolekcjê n obiektów skonstruowanych domyœlnie
- zestaw konstruktor kopiuj¹cy/operator przypisania realizuj¹ce g³êbokie kopie
- zestaw konstruktor przenosz¹cy/operator przypisania z rvalue realizuj¹ce przenoszenie (a mo¿e dostarczone przez kompilator wystarcz¹?)
- destruktor (a mo¿e dostarczony przez kompilator wystarczy?)
- metodê size zwracaj¹c¹ rozmiar w postaci liczby ca³kowitej ze znakiem
- metodê empty zwracaj¹c¹ prawdê wtedy i tylko wtedy gdy kolekcja jest pusta
- zestaw metoda swap oraz wolnostoj¹cy wzorzec funkcji swap
- zestaw operatorów [] zapewniaj¹cych dostêp do elementu kolekcji, sta³ej lub nie
- zestaw operacji push_back, powiêkszaj¹cych wewnêtrzn¹ kolekcjê i umo¿liwiaj¹cych skopiowanie b¹dŸ przeniesienie
  zadanego obiektu pod nowopowsta³y indeks
- zestaw operacji back, zapewniaj¹cych dostêp do ostatniego elementu kolekcji, sta³ej lub nie
- operacjê pop_back, skracaj¹c¹ kolekcjê o element o ostatnim indeksie (i nie robi¹c¹ niczego innego,
  w szczególnoœci nie zwracaj¹c¹ ¿adnej wartoœci)
- zestaw operacji push_front, powiêkszaj¹cych wewnêtrzn¹ kolekcjê i umo¿liwiaj¹cych skopiowanie b¹dŸ przeniesienie
  zadanego obiektu pod nowopowsta³y indeks 0 (elementy dotychczas istniej¹ce w kolekcji otrzymuj¹ numery o jeden wiêksze)
- zestaw operacji front, zapewniaj¹cych dostêp do pierwszego elementu kolekcji, sta³ej lub nie
- operacjê pop_front, skracaj¹c¹ kolekcjê o element o zerowym indeksie i przesuwaj¹c¹ elementy o pozosta³ych indeksach
  na o jeden mniejsze (i nie robi¹c¹ niczego innego, w szczególnoœci nie zwracaj¹c¹ ¿adnej wartoœci)*/

#include <iostream>

int main(void)
{
  test_Vector();

  std::cin.get();
  std::cout << std::endl;
  std::cin.get();

  return 0;
}
