#include "Data.hpp"
#include "Plec.hpp"
#include "Pesel.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <sstream>

/*Umie�� klas� Data w stosownym komplecie plik�w hpp i cpp. Umie�� tam r�wnie� deklaracj� i definicj� operatora wyj�cia <<,
oraz deklaracj� i definicj� funkcji testuj�cej us�ugi tej klasy. Utw�rz klas� Plec (p�e�), i podobnie, umie�� jej kod
wraz z operatorem wyj�cia i funkcj� testuj�c� w stosownym komplecie plik�w. Utw�rz klas� PESEL, wyposa� j� w mo�liwo��
otrzymania zakodowanej w numerze daty urodzenia i p�ci w postaci stosownych obiekt�w, a kod tej klasy i towarzysz�cych
funkcji zn�w umie�� w stosownym komplecie plik�w hpp i cpp. Napisz aplikacj�, kt�ra przetestuje klasy, z kt�rych korzysta
i zademonstruje ich dzia�anie. Je�eli do aplikacji potrzeba dodatkowych operacji w kt�rej� klasie, mo�esz oczywi�cie je
w stosownych miejscach dopisa�, pami�taj aby je r�wnie� testowa�.*/

void test_Daty(void)
{
    Data d(2014,10,19);

    std::ostringstream data;
    data.str("");
    data << d;
    assert(data.str() == "2014.10.19");
    data.str("");

    std::istringstream data2;
    data2.str("2014 11 19");
    Data d2;
    data2 >> d2;
    assert(data2);

    std::cerr << "Klasa Data pomyslnie przeszla testy." << std::endl;
}

void test_Plci(void)
{
    Plec p('k');

    std::ostringstream plec;
    plec.str("");
    plec << p;
    assert(plec.str() == "k");
    assert(p.zwroc_plec() == 'k');

    assert(p.czy_kobieta() == true);

    std::cerr << "Klasa Plec pomyslnie przeszla testy." << std::endl;
}

void test_Pesel(void)
{
    Pesel g("71312502431");
    Pesel s("99072621534");

    assert(g.CzyPoprawny() == false);
    assert(s.CzyPoprawny() == true);

    assert(g.jaka_plec().czy_kobieta() == false);
    assert(s.jaka_plec().czy_kobieta() == true);

    assert(s.Data_ur() == Data(1999,7,26));
    assert(g.Data_ur() == Data(2071,11,25));

    assert(g.Numer() == "71312502431");
    assert(s.Numer() == "99072621534");

    std::cerr << "Klasa Pesel pomyslnie przeszla testy." << std::endl;
}

int main()
{
    test_Daty();
    test_Plci();
    test_Pesel();

    std::cout << std::endl << "Wpisz nr PESEL:" << std::endl;
    Pesel p;
    std::cin >> p;
    std::cout << std::endl <<"Znacznik plci: " << p.jaka_plec();
    std::cout << std::endl <<"Data urodzenia: " << p.Data_ur() << std::endl;

    system("pause");
    return 0;
}
