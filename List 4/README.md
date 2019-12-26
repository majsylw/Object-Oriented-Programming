# Zadania na laboratorium

## Zadanie 1
Jeszcze raz klasa Data. Wyposaż klasę Data w klasy wyjątków, które będzie zgłaszał konstruktor w razie przekazania
nieprawidłowych danych. Wiemy już, że obiekt wyjątku nie powinien zawierać danych, których rozmiar nie jest znany
w czasie kompilacji, ale może zawierać inne dane, na przykład liczby itp (wartość liczby oczywiście nie jest znana,
ale jeżeli przeznaczamy na nią 32-bitowy int, to wiemy, że potrzeba nam czterech bajtów, i cztery jest tym znanym rozmiarem).
Wyposaż klasy wyjątków w atrybuty, które pozwolą odczytać, jakie błędne dane zostały przekazane konstruktorowi.
Przetestuj, czy konstruktor właściwie ustawia te atrybuty w zgłaszanych wyjątkach. Napisz przykładową aplikację,
która je wykorzysta.

## Zadanie 2
Napisz klasę Karta, wstępnie omówioną na wykładzie, której obiekty będą reprezentowały numery kart płatniczych.
Wyposaż ją w konstruktor z argumentem typu std::string, który będzie akceptował numery kart w postaci 16 cyfr,
które mogą być porozdzielane spacjami.

Podobnie jak w zadaniu powyżej, wyposaż klasę Karta, w klasy wyjątków odpowiadających sytuacji przekazania konstruktorowi napisu,
w którym są inne znaki niż cyfry i białe znaki, oraz sytuacji, w której przekazany numer ma z pozoru poprawny format,
ale nie przechodzi testu sumy kontrolnej (algorytm Luhna musi dać zero, poszukaj jego definicji).

Wyposaż obiekty wyjątków w pola umożliwiające przekazanie choć części informacji o błędnie przekazanych danych.
Ponieważ nie powinniśmy definiować atrybutu typu ```std::string``` w wyjątkach, musimy go zastąpić atrybutem-tablicą o stałym rozmiarze,
np. ```char wrong_[40];```, gdzie 40 jest ustalonym w czasie kompilacji rozmiarem bufora (mogą państwo wybrać inny rozmiar,
jeżeli będzie bardziej sensowny). Aby taki atrybut wykorzystać, muszą państwo przekopiować do niego litery,
i zakończyć literą o numerze zero, która informuje system, że napis się już kończy (choć tablica być może jeszcze nie).
Atrybut wrong_, jako tablica, jest typu ```char*```, i można go np. bezpośrednio wypisać na strumień, albo zamienić na ```std::string```
już w klauzuli ```catch```. Do kopiowania liter można użyć funkcji z biblioteki cstring oraz metody ```c_str``` obiektów ```std::string```.
Uwaga: nie należy kopiować więcej liter niż zmieści się w tablicy (razem z końcową literą o numerze zero).
W przeciwnym razie będziemy mieli do czynienia z błędem przepełnienia bufora, jedną z najgroźniejszych luk bezpieczeństwa.

## Zadanie 3
Na wykładzie poznaliśmy sposób alokowania obiektów na stercie, ale nie poznaliśmy do końca sposobów radzenia sobie
z konsekwentnym zwalnianiem niepotrzebnej już pamięci. W tym zadaniu treścią jest napisanie błędnego,
źle skonstruowanego programu, którego jedynym efektem ma być wyciek pamięci, który doprowadzi na koniec do sytuacji,
w której cała pamięć systemowa zostanie przydzielona, i na kolejne obiekty już jej zabraknie. Można to osiągnąć alokując
w pętli dość duże obiekty, na przykład zawierające atrybut tablicowy typu ```char duza_tablica[0x100000];```
(napis 0x100000 to w układzie szesnastkowym 2<sup>20</sup>, czyli tablica ma rozmiar 1MB, można eksperymentować z innymmi rozmiarami),
i nigdy ich nie zwalniać. Brak pamięci jest sygnalizowany przez system przez zgłoszenie wyjątku typu ```std::bad_alloc```.
Ile udało Ci się zaalokować pamięci dla bloków o zadanym rozmiarze zanim pamięć się skończyła?
Uwaga: proszę w czasie eksperymentów pozamykać inne programy z ważnymi dokumentami, ponieważ system może być momentami niestabilny
lub nie odpowiadać na polecenia.

## Zadanie 4
Ryzyko (żargonowy odpowiednik słowa polisa) motoryzacyjne pewnej firmy dzieli się na podryzyka,
dla których osobno oblicza się składkę, i potem sumuje, aby otrzymać składkę za całą polisę. I tak:
-dla podryzyka pożaru składkę oblicza się jako 1% wartości pojazdu,
-dla podryzyka wypadku składkę dla kierowcy w wieku 18-25 oblicza się jako 20% wartości pojazdu pomniejszonej
 o indywidualnie kwotowo ustalony udział własny właściciela a dla kierowcy w wieku 26 i więcej lat jako 10% wartości
 pojazdu pomniejszonej o indywidualnie kwotowo ustalony udział własny właściciela,
-dla podryzyka szkody z przyczyn naturalnych, np. gradu jako 2% wartości pojazdu,
-dla podryzyka odpowiedzialności cywilnej na mieniu 0.03% ustawowej kwoty gwarancyjnej obowiązującej
 w chwili zawarcia umowy (proszę sprawdzić jaka jest w bieżącym roku) obniżona o indywidualny procentowy rabat klienta.
Klient kupując polisę decyduje które opcje wybiera.