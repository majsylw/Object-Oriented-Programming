#include "Data.hpp"
#include "Plec.hpp"
#include "Pesel.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <sstream>

/*Umieœæ klasê Data w stosownym komplecie plików hpp i cpp. Umieœæ tam równie¿ deklaracjê i definicjê operatora wyjœcia <<,
oraz deklaracjê i definicjê funkcji testuj¹cej us³ugi tej klasy. Utwórz klasê Plec (p³eæ), i podobnie, umieœæ jej kod
wraz z operatorem wyjœcia i funkcj¹ testuj¹c¹ w stosownym komplecie plików. Utwórz klasê PESEL, wyposa¿ j¹ w mo¿liwoœæ
otrzymania zakodowanej w numerze daty urodzenia i p³ci w postaci stosownych obiektów, a kod tej klasy i towarzysz¹cych
funkcji znów umieœæ w stosownym komplecie plików hpp i cpp. Napisz aplikacjê, która przetestuje klasy, z których korzysta
i zademonstruje ich dzia³anie. Je¿eli do aplikacji potrzeba dodatkowych operacji w którejœ klasie, mo¿esz oczywiœcie je
w stosownych miejscach dopisaæ, pamiêtaj aby je równie¿ testowaæ.*/

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
