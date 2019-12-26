#include "Pary.hpp"
#include <iostream>

/*Na wyk³adzie widzieliœmy przyk³ad wykorzystania wyj¹tków do zg³oszenia b³êdu braku klucza w operatorze obliczania wartoœci
w pisanym przez nas obiekcie klasy Map (z pierwszej listy zadañ). Dokoñcz przyk³ad: uzupe³nij swoj¹ implementacjê Map o zg³aszanie
tego wyj¹tku, uzupe³nij funkcjê testuj¹c¹ o testowanie zg³aszania wyj¹tku w przypadku braku klucza, i napisz aplikacjê,
która w pêtli pozwoli u¿ytkownikowi na wielokrotny wybór czynnoœci wpisania do bazy nowej pary (klucz,wartoœæ)
(je¿eli jest stary taki sam klucz to wartoœæ zostanie zmieniona na now¹) i odczytania wartoœci dla klucza, a w przypadku braku
klucza przy odczytywaniu, aplikacja prze¿yje, poinformuje u¿ytkownika, i bêdzie czekaæ na kolejne polecenia.
Czy ca³¹ tak¹ aplikacjê da siê testowaæ przy pomocy funkcji testuj¹cej?*/

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
