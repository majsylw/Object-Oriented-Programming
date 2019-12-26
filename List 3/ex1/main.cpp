#include "Pary.hpp"
#include <iostream>

/*Na wyk�adzie widzieli�my przyk�ad wykorzystania wyj�tk�w do zg�oszenia b��du braku klucza w operatorze obliczania warto�ci
w pisanym przez nas obiekcie klasy Map (z pierwszej listy zada�). Doko�cz przyk�ad: uzupe�nij swoj� implementacj� Map o zg�aszanie
tego wyj�tku, uzupe�nij funkcj� testuj�c� o testowanie zg�aszania wyj�tku w przypadku braku klucza, i napisz aplikacj�,
kt�ra w p�tli pozwoli u�ytkownikowi na wielokrotny wyb�r czynno�ci wpisania do bazy nowej pary (klucz,warto��)
(je�eli jest stary taki sam klucz to warto�� zostanie zmieniona na now�) i odczytania warto�ci dla klucza, a w przypadku braku
klucza przy odczytywaniu, aplikacja prze�yje, poinformuje u�ytkownika, i b�dzie czeka� na kolejne polecenia.
Czy ca�� tak� aplikacj� da si� testowa� przy pomocy funkcji testuj�cej?*/

int main()
{
    test_pary();
    std::cout << std::endl;

    char wybor;
    bool exit = false;

    std::string napis;
    double liczba = 0.0;

    Pary p;

    while(true)
    {
        std::cout << "Jaka podjac nastepna czynnosc? \n(dodaj - d; zwroc - z, wypisz pary - w, wyjscie - e)" << std::endl;
        std::cin >> wybor;

        switch(wybor) {
            case 'd':
            case 'D':

                std::cout << "\nPodaj pare - napis i liczbe: \n";
                std::cin >> napis;
                std::cin >> liczba;

                p.dodaj_pare(napis, liczba);
                break;

            case 'z':
            case 'Z':
                std::cout << "\nPodaj klucz napisowy: \n";
                std::cin >> napis;
                try
                {
                    std::cout << std::endl << p.zwroc(napis) << "\n";
                }
                catch(BrakKlucza& e)
                {
                    std::cout << "Brak wartosci dla podanego klucza.\n\n";
                }

                break;

            case 'w':
            case 'W':
                p.wypisz_pary();
                std::cout << std::endl;
                break;

            case 'e':
            case 'E':
                exit = true;
                break;

            default:
                std::cout << "Niepoprawna komenda! Jeszcze raz... \n\n";
        }
        if(exit)
            break;
    }

    return 0;
}
