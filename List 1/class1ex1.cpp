/*Napisz klasê, która bêdzie umia³a przechowywaæ pary z³o¿one z napisu i liczby zmiennoprzecinkowej.
Klasa ta ma modelowaæ funkcjê, której argumentem jest napis, a wartoœci¹ liczba
(tzn. klasa ma mieæ stosown¹ metodê -jak¹ najlepiej?- która wywo³ana z argumentem napisowym zwróci liczbê).
Po skonstruowaniu obiekt tej klasy ma byæ pusty - nie zawieraæ ¿adnych par, ma mieæ jednak mo¿liwoœæ dodawania kolejnych par.
W przypadku dodawania pary, dla klucza której (tzn. napisu) jest ju¿ przypisana jakaœ wartoœæ, nowa wartoœæ ma zast¹piæ star¹.
Jak sygnalizowaæ u¿ytkownikowi, ¿e pyta o wartoœæ dla klucza, dla którego jeszcze wartoœci nie podano?
Napisz funkcjê testuj¹c¹ aby zademonstrowaæ dzia³anie. Nie u¿ywaj bibliotecznej klasy std::map.
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
