# Zadania na laboratorium

## Zadanie 1
Napisz klasę, która będzie umiała przechowywać pary złożone z napisu i liczby zmiennoprzecinkowej.
Klasa ta ma modelować funkcję, której argumentem jest napis, a wartością liczba
(tzn. klasa ma mieć stosowną metodę -jaką najlepiej?- która wywołana z argumentem napisowym zwróci liczbę).
Po skonstruowaniu obiekt tej klasy ma być pusty - nie zawierać żadnych par, ma mieć jednak możliwość dodawania kolejnych par.
W przypadku dodawania pary, dla klucza której (tzn. napisu) jest już przypisana jakaś wartość, nowa wartość ma zastąpić starą.
Jak sygnalizować użytkownikowi, że pyta o wartość dla klucza, dla którego jeszcze wartości nie podano?
Napisz funkcję testującą aby zademonstrować działanie. Nie używaj bibliotecznej klasy ```std::map```.

## Zadanie 2
Napisz wzorzec algorytmu Tokenizer, którego argumentami będzie podzakres kolekcji liter
(kolekcja liter to może być obiekt typu ```std::string```, ale też ```std::vector<char>``` itp.)
oraz iterator docelowy, do jakiejś kolekcji napisów typu ```std::string```. Algorytm ten powinien
podzielić tekst z podzakresu kolekcji liter na wyrazy i umieścić je w kolekcji docelowej.
Za definicję wyrazu przyjmujemy nieprzerwany ciąg liter lub cyfr. Uwaga: ten algorytm będzie
miał dwa parametry we wzorcu, jeden na typ obu iteratorów opisujących zakres, drugi na typ
iteratora docelowego. Nie próbuj od razu pisać wzorca algorytmu, zamiast tego wybierz konkretne
typy wejściowe i wyjściowe, na przykład takie jak na początku poniższej funkcji testującej,
a dopiero potem spróbuj przerobić tę konkretną funkcję na wzorzec. Spróbuj tak napisać swoją
funkcję, korzystając z algorytmów i usług biblioteki standardowej, żeby użyć najwyżej jednej pętli (tylko jednej).