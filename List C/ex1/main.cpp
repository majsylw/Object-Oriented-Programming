#include "Data.hpp"
#include "Pesel.hpp"
#include "Plec.hpp"
#include "Osoba.hpp"

#include <iostream>

/*Rozwazalismy ju¿ wielokrotnie klase modelujaca osoby. Niech tym razem obiekty klasy Osoba skladaja sie z imienia,
nazwiska, okreslenia plci, daty urodzenia i numeru PESEL. Przyklad hierarchii wyjatków zwiazanych z blednymi danymi daty
widzielismy na wykaadzie. Numer PESEL równiez nie jest dowolny: ma okreœlona ilosc cyfr, zawiera cyfre kontrolna,
która musi byc poprawna, aby ciag cyfr mógl byc traktowany jako PESEL, ponadto zawiera zakodowan¹ p³eæ oraz datê urodzenia,
a nie kazda data jest poprawna (szczegoly kodowania PESEL choæby w wikipedii). Co wiecej, oznacza to, ze dane osoby,
choæ indywidualnie poprawne, mogly nie byc spójne (np. data urodzenia inna niz zakodowana w PESELu). Pomyœl nad hierarchi¹ klas
wyjatkow modelujaca mozliwe bledy przy tworzeniu osób i atrybutów osób. Spróbuj znalezc kategorie bledów i wydzielic je
jako klasy bazowe. Poniewaz bedziesz mieæ do czynienia z dziedziczeniem wielokrotnym i diamond-shaped inheritance diagram
(chocby dlatego, ze klasy wyjatków maja mieæ wspólnego przodka: std::exception), pomyœl o u¿yciu dziedziczenia wirtualnego.*/


int main()
{
    std::string imie, nazwisko, pesel;
    char plec;
    int rok, miesiac, dzien;

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "    Imie: ";
    std::cin >> imie;
    std::cout << "Naziwsko: ";
    std::cin >> nazwisko;
    std::cout << "   Pesel: ";
    std::cin >> pesel;
    std::cout << "    Plec: ";
    std::cin >> plec;
    std::cout << "     Rok: ";
    std::cin >> rok;
    std::cout << " Miesiac: ";
    std::cin >> miesiac;
    std::cout << "   Dzien: ";
    std::cin >> dzien;
    std::cout << "---------------------------------------------------" << std::endl;

    try {
        Osoba nowa( imie, nazwisko, pesel, plec, rok, miesiac, dzien );
        std::cout << "Dane wpisano legitymujaco!" << std::endl;

    } catch(Osoba::NiespojnaData e) {
        std::cout << e.what() << std::endl;

    } catch(Osoba::BrakSpojnosci e) {
        std::cout << e.what() << std::endl;

    } catch(std::exception e) {
        std::cout << e.what() << std::endl;
    }

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
