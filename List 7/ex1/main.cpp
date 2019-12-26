#include "Vector.hpp"

/*Zaprojektuj i zaprogramuj wzorzec klasy Vector. Obiekty tej klasy b�d� przechowywa�y obiekty zadanego typu,
w spos�b zbli�ony do std::vector, cho� z pewnymi r�nicami. Biblioteczny typ std::vector rezerwuje miejsce na stercie na zapas,
na obiekty, kt�re dopiero w�o�ymy do kolekcji (np. przez push_back albo insert), poza tym, w momencie usuwania obiekt�w
z kolekcji (np. przez pop_back) nie zmniejsza wewn�trznych danych, tylko traktuje miejsce po usuni�tych jako rezerw�.
Nasza klasa Vector powinna si� zachowywa� inaczej: rozmiar wewn�trznej tablicy powinien dok�adnie odpowiada� ilo�ci danych
w ka�dej chwili (z uwzgl�dnieniem szczeg�lnego stanu pustego). Do zarz�dzania czasem �ycia wewn�trznej tablicy nale�y u�y�
atrybutu typu std::unique_ptr. Wyposa� klas� w nast�puj�ce operacje:
- konstruktor domy�lny, tworz�cy pust� kolekcj�
- konstruktor z liczby ca�kowitej n ze znakiem tworz�cy kolekcj� n obiekt�w skonstruowanych domy�lnie
- zestaw konstruktor kopiuj�cy/operator przypisania realizuj�ce g��bokie kopie
- zestaw konstruktor przenosz�cy/operator przypisania z rvalue realizuj�ce przenoszenie (a mo�e dostarczone przez kompilator wystarcz�?)
- destruktor (a mo�e dostarczony przez kompilator wystarczy?)
- metod� size zwracaj�c� rozmiar w postaci liczby ca�kowitej ze znakiem
- metod� empty zwracaj�c� prawd� wtedy i tylko wtedy gdy kolekcja jest pusta
- zestaw metoda swap oraz wolnostoj�cy wzorzec funkcji swap
- zestaw operator�w [] zapewniaj�cych dost�p do elementu kolekcji, sta�ej lub nie
- zestaw operacji push_back, powi�kszaj�cych wewn�trzn� kolekcj� i umo�liwiaj�cych skopiowanie b�d� przeniesienie
  zadanego obiektu pod nowopowsta�y indeks
- zestaw operacji back, zapewniaj�cych dost�p do ostatniego elementu kolekcji, sta�ej lub nie
- operacj� pop_back, skracaj�c� kolekcj� o element o ostatnim indeksie (i nie robi�c� niczego innego,
  w szczeg�lno�ci nie zwracaj�c� �adnej warto�ci)
- zestaw operacji push_front, powi�kszaj�cych wewn�trzn� kolekcj� i umo�liwiaj�cych skopiowanie b�d� przeniesienie
  zadanego obiektu pod nowopowsta�y indeks 0 (elementy dotychczas istniej�ce w kolekcji otrzymuj� numery o jeden wi�ksze)
- zestaw operacji front, zapewniaj�cych dost�p do pierwszego elementu kolekcji, sta�ej lub nie
- operacj� pop_front, skracaj�c� kolekcj� o element o zerowym indeksie i przesuwaj�c� elementy o pozosta�ych indeksach
  na o jeden mniejsze (i nie robi�c� niczego innego, w szczeg�lno�ci nie zwracaj�c� �adnej warto�ci)*/

#include <iostream>

int main(void)
{
  test_Vector();

  std::cin.get();
  std::cout << std::endl;
  std::cin.get();

  return 0;
}
