#include "Pary.hpp"
#include "Gielda.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

/*Umieœæ swoje rozwi¹zanie zadania pierwszego z poprzedniej listy, dotycz¹cego klasy reprezentuj¹cej
funkcjê z napisów w liczby zmiennoprzecinkowe, w stosownym komplecie plików hpp i cpp. Napisz klasê Gielda,
która bêdzie reprezentowaæ konkretna gieldê papierów wartoœciowych, i która bêdzie mia³a nazwê, oraz bie¿¹ce
kursy spó³ek na niej notowanych zaimplementowane przy pomocy obiektu klasy z poprzedniej listy (upraszczamy
w ten sposób, ¿e dla ka¿dej spó³ki mamy jeden kurs, mo¿emy o nim myœleæ jako o œredniej prawdziwych kursów
kupna i sprzeda¿y). ZnajdŸ w internecie dwie-trzy gie³dy wraz z symbolami kilku spó³ek na nich notowanych i
u¿yj ich w testach. Napisz aplikacjê, która wywo³a testy
*/

void test_pary(void)
{
    Pary d;
    d.dodaj_pare("Dwa",2);
    d.dodaj_pare("Trzy", 3);
    d.dodaj_pare("Jeden", 1);
    assert(d.zwroc("Dwa") == 2);
    d.dodaj_pare("Dwa", 0);
    assert(d.zwroc("Dwa") == 0);

    std::cerr << "Test_Pary przeszedl pomyslnie." << std::endl;
}


void test_gieldy(void)
{
    Pary k1;
    k1.dodaj_pare("BASF SE",69.32);
    k1.dodaj_pare("Lanxess",39.72);
    k1.dodaj_pare("NOVO NORDISK ADR",34.19);
    k1.dodaj_pare("CONTINENTAL STK",151.89);
    k1.dodaj_pare("VOLKSWAGEN Vorzüge",160.22);
    k1.dodaj_pare("HYUNDAI MOTOR GDR",39.27);
    k1.dodaj_pare("Twitter",38.65);
    k1.dodaj_pare("Aareal Bank AG",29.98);
    k1.dodaj_pare("MORPHOSYS STK",67.06);
    k1.dodaj_pare("APPLE COMPUTER STK",76.60);
    Gielda g1("Berliner Börse",k1);

    Pary k2;
    k2.dodaj_pare("JACQUES BOGART",24.03);
    k2.dodaj_pare("4ENERGY INVEST",3.50);
    k2.dodaj_pare("TECHNICOLOR",4.41);
    k2.dodaj_pare("NEDAP",26.995);
    k2.dodaj_pare("NEURONES",12.9);
    k2.dodaj_pare("ACCENTIS",0.016);
    k2.dodaj_pare("ZODIAC AEROSPACE",22.975);
    k2.dodaj_pare("L'OREAL",119.35);
    k2.dodaj_pare("CAST",2.6);
    k2.dodaj_pare("NATIX",5.155);
    Gielda g2("Euronext Lisbon", k2);

    Pary k3;
    k3.dodaj_pare("LOTOS",27.79);
    k3.dodaj_pare("SYNTHOS",3.98);
    k3.dodaj_pare("GTC",5.45);
    k3.dodaj_pare("JSW",28.5);
    k3.dodaj_pare("PEKAO",179.3);
    k3.dodaj_pare("LPP",9700.00);
    k3.dodaj_pare("PGE",21.17);
    k3.dodaj_pare("TAURONPE",5.15);
    k3.dodaj_pare("PZU",471.00);
    k3.dodaj_pare("MBANK",485.00);
    Gielda g3("GPW Warszawa", k3);


    std::cerr << "Test_gieldy przeszedl pomyslnie." << std::endl;
}

int main()
{
    test_pary();
    test_gieldy();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
