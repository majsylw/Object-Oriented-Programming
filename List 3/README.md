# Zadania na laboratorium

## Zadanie 1
Na wykładzie widzieliśmy przykład wykorzystania wyjątków do zgłoszenia błędu braku klucza w operatorze obliczania wartości
w pisanym przez nas obiekcie klasy Map (z pierwszej listy zadań). Dokończ przykład: uzupełnij swoją implementację ```Map``` o zgłaszanie
tego wyjątku, uzupełnij funkcję testującą o testowanie zgłaszania wyjątku w przypadku braku klucza, i napisz aplikację,
która w pętli pozwoli użytkownikowi na wielokrotny wybór czynności wpisania do bazy nowej pary (klucz,wartość)
(jeżeli jest stary taki sam klucz to wartość zostanie zmieniona na nową) i odczytania wartości dla klucza, a w przypadku braku
klucza przy odczytywaniu, aplikacja przeżyje, poinformuje użytkownika, i będzie czekać na kolejne polecenia.
Czy całą taką aplikację da się testować przy pomocy funkcji testującej?

## Zadanie 2
Wyposaż konstruktor klasy ```Data``` w obsługę błędnych argumentów poprzez wyjątki. Zrób to w taki sposób,
aby być w stanie w kodzie klienckim stwierdzić jaka kategoria błędu nastąpiła (zły rok, np. 0,
zły miesiąc, spoza 1-12, zły dzień w danym miesiącu). Napisz operator wejścia ```operator>>``` dla typu ```Data```,
w którym nie będziesz sprawdzać czy wczytane trzy liczby typu int mają sensowne wartości, tylko wywołasz z nimi konstruktor Data,
który zajmie się sprawdzaniem. Napisz funkcję testującą wszystkie te usługi, ze sprawdzeniem, czy w określonych sytuacjach wyjątki
rzeczywiście są zgłaszane. Wszystko, jak zwykle, umieść w stosownych plikach.

Napisz aplikację, w której skorzystasz z powyższego operatora wejścia (np. wczytasz datę ze strumienia i wypiszesz,
czy była ona prawidłowa czy nie). Zauważ, że masz teraz dwa rodzaje błędów, różnie obsługiwanych. Jeżeli nie udało się wczytać
trzech liczb, strumień będzie zepsuty. Jeżeli się udało, ale nie spełniają one kryteriów, będzie zgłoszony wyjątek.
Spróbuj przeczytać w dokumentacji, jak można namówić strumień żeby zgłaszał wyjątek również w pierwszym scenariuszu
(np. tu: ```http://en.cppreference.com/w/cpp/io/basic_ios/exceptions```). Spróbuj przestawić stan strumienia w taki sposób,
aby w każdej sytuacji odtworzyć stan uprzedni. Omawialiśmy jak to można zrobić w zeszłym semestrze, jeden ze scenariuszy jest
opisany np. tu: ```http://ljwo.wordpress.com/2014/05/14/stdios_base-format-flags-are-a-resource-that-needs-raii/```
(tzn. w tym artykule jest opisana technika, którą należy zaadaptować do flag strumienia opisujących zgłaszane wyjątki,
 o których jest mowa w dokumentacji basic_ios/exceptions powyżej).

## Zadanie 3
Przerób funkcję liczącą największy wspólny dzielnik dla dwóch liczb typu ```int```,
omawianą w zeszłym semestrze, na wzorzec funkcji liczącej największy wspólny dzielnik
dla dwóch liczb dowolnego ale tego samego typu (od którego wymagamy oczywiście stosownych
operacji arytmetycznych używanych w obliczeniach). Do wzorca dołącz funkcję testującą go
dla konkretnych danych konkretnego typu (np. ```int```). Umieść ten wzorzec i funkcję testującą
w stosownym pliku/plikach. Napisz klasę Wymierna, która będzie reprezentować liczbę wymierną.
Zaimplementuj ją tak, żeby przechowywała już skrócone licznik i mianownik jako atrybuty prywatne typu long.
Konstruktor napisz jako zwykłą metodę, a akcesory licznika i mianownika napisz jako metody inline.
W tym zadaniu warunki sensowności w konstruktorze wymuszaj przez assert. Nie rozbudowuj tej klasy ponad potrzebę,
omawiać będziemy tylko to, o czym jest jawnie mowa w tym poleceniu. Napisz również funkcję testującą usługi tej klasy,
a wszystko umieść w stosownych plikach. Napisz aplikację, która co najmniej wywoła testy dla reszty kodu.

## Zadanie 4
W zeszłym semestrze uczyliśmy się o prostym dziedziczeniu. Zaprojektuj prostą hierarchię klas, w której klasa bazowa będzie
reprezentowała podatnika, i której interfejs (wirtualna metoda) będzie umożliwiała otrzymanie napisu z danymi podatnika.
Spróbuj zadeklarować w klasie bazowej również destruktor jako wirtualny i zdefiniować go z pustym ciałem funkcji
(będzie wytłumaczone dlaczego).
Napisz trzy klasy pochodne, reprezentujące podatników określonego rodzaju: osoby fizyczne, opisane imieniem, nazwiskiem,
datą urodzenia i numerem pesel, firmy, opisane nazwą i numerem NIP, oraz fundacje, opisane nazwą, numerem KRS oraz informacją,
czy są pożytku publicznego, czy nie. Każdą z klas pochodnych wyposaż w wersję wirtualnej metody do generowania napisu z danymi
podatnika.

Po drugie, napisz funkcję, która dla przekazanej referencji do strumienia wejściowego podejmie próbę rozpoznania,
jakiej kategorii, osoby, firmy, czy fundacji dane znajdują się na początku wejścia, i która, po udanym wczytaniu kompletu danych,
utworzy obiekt stosownej klasy pochodnej na stercie, wskaźnik do niego umieszczając od razu w obiekcie ```std::unique_ptr```
przechowującym wskaźnik do klasy bazowej, a następnie ten obiekt ```std::unique_ptr``` zwróci jako swoją wartość.
Dane dla osoby będą się zaczynać od <osoba i kończyć na ```>```, podobnie dane dla firmy będą się zaczynać od <firma i kończyć na >,
a dla fundacji zaczynać od ```<fundacja``` i kończyć na ```>```. Można założyć, że dane są poprawne i nie walczyć o szczgółową diagnostykę
błędów wejścia.

Po trzecie, napisz funkcję, która dla otrzymanej referencji do strumienia wejściowego będzie wywoływać funkcję z punktu trzeciego
aż do wyczerpania strumienia, a otrzymane obiekty ```std::unique_ptr``` będzie kolejno umieszczać w stosownym wektorze, który zwróci
na koniec jako swoją wartość.

Po czwarte, wywołaj funkcję z punktu czwartego z jakimiś przygotowanymi danymi, a następnie, dla każdego podatnika w otrzymanej
kolekcji wyświetl jego dane (ewentualnie sprawdź w funkcji testującej czy dane są poprawnie odczytane).