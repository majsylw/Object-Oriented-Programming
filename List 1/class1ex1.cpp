/*Napisz klas�, kt�ra b�dzie umia�a przechowywa� pary z�o�one z napisu i liczby zmiennoprzecinkowej.
Klasa ta ma modelowa� funkcj�, kt�rej argumentem jest napis, a warto�ci� liczba
(tzn. klasa ma mie� stosown� metod� -jak� najlepiej?- kt�ra wywo�ana z argumentem napisowym zwr�ci liczb�).
Po skonstruowaniu obiekt tej klasy ma by� pusty - nie zawiera� �adnych par, ma mie� jednak mo�liwo�� dodawania kolejnych par.
W przypadku dodawania pary, dla klucza kt�rej (tzn. napisu) jest ju� przypisana jaka� warto��, nowa warto�� ma zast�pi� star�.
Jak sygnalizowa� u�ytkownikowi, �e pyta o warto�� dla klucza, dla kt�rego jeszcze warto�ci nie podano?
Napisz funkcj� testuj�c� aby zademonstrowa� dzia�anie. Nie u�ywaj bibliotecznej klasy std::map.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Pary
{
    std::vector<std::string> napisy;
    std::vector<double> liczby;

public:

    double zwroc (std::string napis)
    {
        assert(napisy.size() == liczby.size());

        unsigned int i=0;
        for(i=0; i < napisy.size(); ++i)
        {
            if(napisy[i] == napis)
                break;
        }

        assert(i < napisy.size());

        return liczby[i];
    }

    void dodaj_pare (std::string napis, double liczba)
    {
        assert(napisy.size() == liczby.size());

        unsigned int i=0;
        for(i=0; i < napisy.size(); ++i)
        {
            if(napisy[i] == napis)
                break;
        }

        if(i == napisy.size())
        {
            napisy.push_back(napis);
            liczby.push_back(liczba);
        }
        else
        {
            liczby[i] = liczba;
        }

    }

    void wypisz_pary(void)
    {
        assert(napisy.size() == liczby.size());

        for(unsigned int i=0; i < napisy.size(); ++i)
        {
            std::cout << napisy[i] << '\t' << liczby[i] << '\n';
        }
    }

};


void testy(void)
{
    Pary d;
    d.dodaj_pare("Szymon",22);
    d.dodaj_pare("Sylwia", 21);
    d.dodaj_pare("Tomasz", 21);
    assert(d.zwroc("Szymon") == 22);
    d.dodaj_pare("Szymon", 20);
    assert(d.zwroc("Szymon") == 20);

    d.wypisz_pary();

    std::cerr << "Testy przeszly pomyslnie." << std::endl;
}

int main(void)
{
    testy();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
