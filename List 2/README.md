# Zadania na laboratorium

## Zadanie 1
Umieść swoje rozwiązanie zadania pierwszego z poprzedniej listy, dotyczącego klasy reprezentującej
funkcję z napisów w liczby zmiennoprzecinkowe, w stosownym komplecie plików hpp i cpp. Napisz klasę ```Gielda```,
która będzie reprezentować konkretna gieldę papierów wartościowych, i która będzie miała nazwę, oraz bieżące
kursy spółek na niej notowanych zaimplementowane przy pomocy obiektu klasy z poprzedniej listy (upraszczamy
w ten sposób, że dla każdej spółki mamy jeden kurs, możemy o nim myśleć jako o średniej prawdziwych kursów
kupna i sprzedaży). Znajdź w internecie dwie-trzy giełdy wraz z symbolami kilku spółek na nich notowanych i
użyj ich w testach. Napisz aplikację, która wywoła testy

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

## Zadanie 3
Umieść klasę Data w stosownym komplecie plików hpp i cpp. Umieść tam również deklarację i definicję operatora wyjścia ```<<```,
oraz deklarację i definicję funkcji testującej usługi tej klasy. Utwórz klasę Plec (płeć), i podobnie, umieść jej kod
wraz z operatorem wyjścia i funkcją testującą w stosownym komplecie plików. Utwórz klasę PESEL, wyposaż ją w możliwość
otrzymania zakodowanej w numerze daty urodzenia i płci w postaci stosownych obiektów, a kod tej klasy i towarzyszących
funkcji znów umieść w stosownym komplecie plików hpp i cpp. Napisz aplikację, która przetestuje klasy, z których korzysta
i zademonstruje ich działanie. Jeżeli do aplikacji potrzeba dodatkowych operacji w którejś klasie, możesz oczywiście je
w stosownych miejscach dopisać, pamiętaj aby je również testować.