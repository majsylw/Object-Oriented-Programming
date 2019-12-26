# Zadania na laboratorium

## Zadanie 1
Spróbuj zastanowić się, jak zmienić strukturę programu, który pojawił się na wykładzie, tak aby uniknąć zbiegania się
różnych ścieżek dziedziczenia na wspólnej klasie bazowej. Dla przypomnienia, mieliśmy
-klasę bazową ```Podatnik```, która przetwarzała numery nip oraz miała wirtualny destruktor i wirtualną metodę wizytowka
 pozwalającą na wypisanie danych podatnika,
-klasę pochodną ```OsobaFizyczna```, która dziedziczyła publicznie po klasie Podatnik i przetwarzała imię i nazwisko,
 i przedefiniowywała (w sensie override) metodę wizytowka,
-klasę pochodną ```Firma```, która dziedziczyła publicznie po klasie Podatnik i przetwarzała numer regon,
 i przedefiniowywała (w sensie override) metodę wizytowka,
-klasę pochodną ```Dzialalnosc```, która dziedziczyła publicznie po klasie OsobaFizyczna oraz po klasie Firma,
 i przedefiniowywała (w sensie override) metodę wizytowka.
Klasa ```Dzialalnosc``` zawiera dwa potencjalnie różne obiekty typu ```Podatnik```, co jest sporym kłopotem.
Zaproponuj jakieś wyjście z sytuacji. Przeprojektuj hierarchię, nie używaj dziedziczenia wirtualnego.

## Zadanie 2
Rozpatrujemy klasę Person, która przetwarza informacje o osobach, tj. co najmniej ich imiona i nazwiska. Potrzebujemy, dla celów, powiedzmy, diagnostycznych, możliwości wypisania na zadany strumień wszystkich istniejących (tj. skonstruowanych i jeszcze nie usuniętych) w programie obiektów klasy Person.

<pre>
class Worker
  {
    Person person_;
    std::string position_;
  public:
    Worker(const Person& person, std::string position)
      : person_(person)
      , position_(position)
      {
      }
  };

void Fun2(void)
  {
  Person s("Dariusz", "Dabacki");
  Person t("Eugeniusz", "Ebacki");
    {
    Person u("Franciszek", "Fabacki");
    }
  Worker w(Person("Grzegorz","Gabacki"),"guard");
  Person::OutputPersons(std::cout);
  }

void Fun(void)
  {
  Person* pq = new Person("Bartosz", "Babacki");
  Person r("Czeslaw", "Cabacki");
  Fun2();
  delete pq;
  }

int main(void)
{
  Person p("Adam", "Abacki");
  Fun();
  return 0;
}
</pre>

wyprodukował wyjście:
<pre>
lista osob:
Adam Abacki
Bartosz Babacki
Czeslaw Cabacki
Dariusz Dabacki
Eugeniusz Ebacki
Grzegorz Gabacki
</pre>