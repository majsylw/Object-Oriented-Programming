# Zadania na laboratorium

## Zadanie 1
Rozwazalismy już wielokrotnie klase modelujaca osoby. Niech tym razem obiekty klasy Osoba skladaja sie z imienia,
nazwiska, okreslenia plci, daty urodzenia i numeru PESEL. Przyklad hierarchii wyjatków zwiazanych z blednymi danymi daty
widzielismy na wykaadzie. Numer PESEL równiez nie jest dowolny: ma określona ilosc cyfr, zawiera cyfre kontrolna,
która musi byc poprawna, aby ciag cyfr mógl byc traktowany jako PESEL, ponadto zawiera zakodowaną płeć oraz datę urodzenia,
a nie kazda data jest poprawna (szczegoly kodowania PESEL choćby w wikipedii). Co wiecej, oznacza to, ze dane osoby,
choć indywidualnie poprawne, mogly nie byc spójne (np. data urodzenia inna niz zakodowana w PESELu). Pomyśl nad hierarchią klas
wyjatkow modelujaca mozliwe bledy przy tworzeniu osób i atrybutów osób. Spróbuj znalezc kategorie bledów i wydzielic je
jako klasy bazowe. Poniewaz bedziesz mieć do czynienia z dziedziczeniem wielokrotnym i diamond-shaped inheritance diagram
(chocby dlatego, ze klasy wyjatków maja mieć wspólnego przodka: std::exception), pomyśl o użyciu dziedziczenia wirtualnego.