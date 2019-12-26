# Zadania na laboratorium

## Zadanie 1
Napisz klasę IntTab, która będzie zarządzać tablicą liczb typu ```int```, o rozmiarze podanym w konstruktorze.
Podstawowy konstruktor tej klasy ma sam podjąć próbę zaalokowania tablicy, a destruktor jej zwolnienia.
Nie korzystamy w tym zadaniu ani z ```TabOptional``` ani z ```unique_ptr```. Poza konstruktorem i destruktorem wyposaż klasę również w:
- metodę ```size```, która zwróci rozmiar wewnętrznie przechowywanej tablicy,
- konstruktor kopiujący oraz operator przypisania zgodne ze strategią głębokiej kopii
- medotę ```swap``` pozwalającą na wymianę zawartości dwóch obiektów typu IntTab
- dwa operatory ```[]```, const oraz nie-const, które pozwolą na odczyt i zapis wartości pod określonymi indeksami tablicy.

## Zadanie 2
Przygotuj trzy wersje klasy ```IntTab``` z zadania 1 (w takiej wersji, w której można zadeklarować konstruktor przenoszący
i operator przypisania z rvalue jako noexcept):

- wyposażoną zarówno w konstruktor kopiujący i operator przypisania,
jak i w konstruktor przenoszący i operator przypisania z rvalue, oba ostatnie z deklaracją noexcept,

- wyposażoną zarówno w konstruktor kopiujący i operator przypisania,
jak i w konstruktor przenoszący i operator przypisania z rvalue, oba ostatnie bez deklaracji noexcept,

- wyposażoną jedynie w konstruktor kopiujący i operator przypisania
(jak wiemy, konstruktora przenoszącego i operatora przypisania z rvalue kompilator nam sam z siebie
 w tym przypadku nie dodefiniuje).

Zaprojektuj eksperyment, w którym skorzystasz z kolekcji standardowej std::vector do przechowywania obiektów raz jednej,
raz drugiej, a raz trzeciej odmiany IntTab w taki sposób, aby zmusić ją do wielokrotnej wewnętrznej realokacji
(np. dokładając wiele razy po jednym elemencie). Zmierz czasy eksperymentów z poszczególnymi wariantami i porównaj.
Czasy możesz zmierzyć korzystając np. ze wskazówek zawartych tu: ```http://en.cppreference.com/w/cpp/chrono```

Spróbuj również zmienić build target w ```Code::Blocks``` z ```Debug``` na ```Release```, czyli na taki z włączonymi optymalizacjami kompilatora,
i wtedy popatrzeć na czasy.

## Zadanie 3
Przerób rozwiazanie zadania 1 na wzorzec ```Tab```, pozwalajacy przechowywać w wewnętrznej tablicy obiekty dowolnie wybranego typu
(przy typowym rozwiazaniu okaże sie, ze dowolnie wybranego, ale posiadajacego konstruktor domyslny, np. klasa ```Grid``` (podana poniżej) jest w porzadku,
 ale ```Tab<Data>``` sie nie skompiluje).

<pre>
class Grid
  {
    int x_, y_;
  public:
    Grid(int x=0, int y=0) : x_(x), y_(y) {}
    int X(void) const {return x_;}
    int Y(void) const {return y_;}
  };
bool operator==(Grid g1, Grid g2) {return (g1.X()==g2.X())&&(g1.Y()==g2.Y());}
std::ostream& operator<<(std::ostream& wy, Grid g) {return wy<<'('<<g.X()<<','<<g.Y()<<')';}
</pre>