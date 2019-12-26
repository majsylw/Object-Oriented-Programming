#include "Data.hpp"
#include "Pesel.hpp"
#include "Plec.hpp"
#include "Osoba.hpp"

#include <iostream>

/*Rozwazalismy ju� wielokrotnie klase modelujaca osoby. Niech tym razem obiekty klasy Osoba skladaja sie z imienia,
nazwiska, okreslenia plci, daty urodzenia i numeru PESEL. Przyklad hierarchii wyjatk�w zwiazanych z blednymi danymi daty
widzielismy na wykaadzie. Numer PESEL r�wniez nie jest dowolny: ma okre�lona ilosc cyfr, zawiera cyfre kontrolna,
kt�ra musi byc poprawna, aby ciag cyfr m�gl byc traktowany jako PESEL, ponadto zawiera zakodowan� p�e� oraz dat� urodzenia,
a nie kazda data jest poprawna (szczegoly kodowania PESEL cho�by w wikipedii). Co wiecej, oznacza to, ze dane osoby,
cho� indywidualnie poprawne, mogly nie byc sp�jne (np. data urodzenia inna niz zakodowana w PESELu). Pomy�l nad hierarchi� klas
wyjatkow modelujaca mozliwe bledy przy tworzeniu os�b i atrybut�w os�b. Spr�buj znalezc kategorie bled�w i wydzielic je
jako klasy bazowe. Poniewaz bedziesz mie� do czynienia z dziedziczeniem wielokrotnym i diamond-shaped inheritance diagram
(chocby dlatego, ze klasy wyjatk�w maja mie� wsp�lnego przodka: std::exception), pomy�l o u�yciu dziedziczenia wirtualnego.*/


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
