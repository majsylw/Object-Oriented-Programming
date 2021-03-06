#include "TabRIter.hpp"
#include <iostream>

/*Trescia zadania jest napisanie wzorca klasy TabRIter, ktorej obiekty beda sie zachowywaly podobnie jak iteratory do tablic
zadanego typu (czyli podobnie jak wskazniki do tych tablic), z tą oznicą, ze beda zadana tablice ujmowac w odwrotnej kolejnosci,
koniec będzie na indeksie 0, początek tam, gdzie tablica normalnie ma koniec. Odwrotnie będą również działać operacje ++ oraz --,
mianowicie ++ bedzie przesuwać punkt na który obiekt typu TabRIter wskazuje w kierunku indeksu 0, a -- będzie przesuwać punkt
na który obiekt typu TabRIter wskazuje w kierunku indeksów rosnących. Typ, który jest parametrem wzorca TabRIter będzie taki
jak typ danych przechowywanych w tablicy. Do tworzenia obiektów typu TabRIter będziemy potrzebowali wzorców dwóch funkcji
wolnostojących, rbegin oraz rend, które będziemy wywoływać z tablicą (czyli wskaźnikiem na element o indeksie 0) i jej rozmiarem.

UWAGA 1: przy normalnych wskaźnikach do tablic jest tak, że legalne wartości wskaźników są takie jak adresy wszystkich
istniejących w tablicy elementów oraz adres hipotetycznego elementu ,,pierwszego za ostatnim''. Nie jest natomiast legalna
wartość wskaźnika do hipotetycznego elementu poprzedzajacego pierwszy. To oznacza, ze zeby zaimplementować iterator
do elementu pierwszego za ostatnim ale w odwróconej kolejności trzeba się dobrze zastanowić nad tym, co chcemy przechowywać
w iteratorze i jak z tego korzystac.

UWAGA 2: Iterator nie jest właścicielem tablicy, do której się odnosi, ani elementu, który wskazuje. Niczego więc nie kasuje
w destruktorze, i tak naprawdę w ogóle destruktora zazwyczaj nie potrzebuje. Sama tablica dla której tworzymy iterator może być
zaalokowana na stosie a nie na stercie, jak w testach poniżej, więc w całym zadaniu może nie być ani jednego new i ani jednego
delete. Nie ma również w związku z tym żadnego problemu z płytkimi kopiami i operacją przypisania: kopia odnośnika jest innym
odnośnikiem do tego samego elementu.

Napisz wzorzec klasy TabRIter zależący od parametru Value. Wybierz sposób reprezentowania z uwzględnieniem uwagi 1 i stosownie
do tego wyposaż go w konstruktor. Wyposaż wzorzez TabRIter w

- operator -> pozwalający na wywoływanie metod dla wskazywanego obiektu,

- operatory ++ prefiksowy i posfiksowy, przesuwające iterator w stronę początku tablicy,
z uwzględnieniem specjalnej reprezentacji elementu ,,pierwszego za ostatnim'' w odwróconej kolejności,

- operatory -- prefiksowy i posfiksowy, przesuwające iterator w stronę końca tablicy,
z uwzględnieniem tego, że możemy chcieć cofnąć się z iteratorem z wartości odpowiadającej wskazaniu na element
,,pierwszy za ostatnim'' w odwróconej kolejności,

- operator * zwracający referencję do wskazywanego elementu,

- operatory == oraz != sprawdzajace, czy dwa iteratory odnoszą się do tego samego elementu.

Napisz wzorce dwóch funkcji, rbegin oraz rend, które dla tablicy i jej długości zwrócą stosowny obiekt typu TabRIter.

Pytanie dodatkowe: funkcje rbegin oraz rend mają komplet informacji potrzebnych do utworzenia obiektu typu TabRIter,
i są podstawowym narzędziem ich tworzenia. Wywołanie bezpośrednio konstruktora może natomiast być związane
z przekazywaniem nieintuicyjnych argumentów, w zależności od wybranej implementacji. Jak zrobić tak, aby wyłączyć
wywoływanie konstruktora bezpośrednio, bez korzystania z rbegin oraz rend?
*/

int main()
{
    test_TabRIter();

    return 0;
}
