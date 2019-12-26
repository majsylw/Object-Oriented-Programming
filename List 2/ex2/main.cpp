#include "Punkt.h"
#include "Droga.h"
#include "Prosta.h"
#include <iostream>
#include <cassert>


/*Zdefiniuj klas� Punkt reprezentuj�c� punkt na p�aszczy�nie (b�dziemy potrzebowali tylko wsp�rz�dnych kartezja�skich),
i umie�� jej kod wraz z funkcj� testuj�c� w stosownym komplecie plik�w hpp i cpp. Zdefiniuj klas� Droga reprezentuj�c�
drog� sk�adaj�c� si� z odcink�w pomi�dzy kolejnymi zadanymi punktami i potrafi�c� obliczy� swoj� d�ugo��. Umie�� jej kod
wraz z funkcj� testuj�c� w stosownym komplecie plik�w hpp i cpp. Zdefiniuj klas� Prosta reprezentuj�c� prost� na p�aszczy�nie.
Wyposa� j� co najmniej w konstruktor pozwalaj�cy zada� dwa punkty, przez kt�re ma ona przechodzi�, oraz w metody pozwalaj�ce
odczyta� wsp�czynnik kierunkowy i przesuni�cie przy interpretacji prostej jako funkcji liniowej (jakie tu s� szczeg�lne przypadki?).
Umie�� jej kod wraz z funkcj� testuj�c� w stosownym komplecie plik�w hpp i cpp. Napisz aplikacj�, kt�ra przetestuje klasy,
z kt�rych korzysta i zademonstruje ich dzia�anie. Je�eli do aplikacji potrzeba dodatkowych operacji w kt�rej� klasie,
mo�esz oczywi�cie je w stosownych miejscach dopisa�, pami�taj aby je r�wnie� testowa�.*/


void testy(void)
{
    Punkt p1(2,4);
    Punkt p2(0,1);
    Punkt p3(1,1);

    assert(p1.podaj_x() == 2);
    assert(p2.podaj_y() == 1);

    Droga d;
    d.dodaj_punkt(p1);
    d.dodaj_punkt(p2);
    d.dodaj_punkt(p3);

    double a = sqrt(4+9)+sqrt(1+0);
    assert(d.dlugosc() == a);
    Punkt p4(2,3);
    d.dodaj_punkt(p4);
    assert(d.dlugosc() == a+sqrt(1+4));

    Punkt p5(2,5);
    Punkt p6(3,7);
    Prosta pr(p5,p6);

    assert(pr.wspolczynnik_kierunkowy_prostej() == 2);
    assert(pr.wspolczynnik_przesuniecia_prostej() == 1);

    std::cerr << "Program pomyslnie przeszedl testy." << std::endl;
}

int main()
{
    testy();

    Punkt p1,p2,p3;

    std::cout << std::endl << "Podaj 3 punkty lamanej: ";
    std::cin >> p1 >> p2 >> p3;

    Droga d;
    d.dodaj_punkt(p1);
    d.dodaj_punkt(p2);
    d.dodaj_punkt(p3);

    std::cout << std::endl << "Dlugosc lamanej wynosi: " << d.dlugosc() << std::endl;
    std::cout << "A rownania poszczegolnych prostych prezentuja sie nastepujaco:" << std::endl;

    Prosta pr1(p1,p2);
    Prosta pr2(p2,p3);

    std::cout << "y1 = " << pr1.wspolczynnik_kierunkowy_prostej() << "x ";
    if(pr1.wspolczynnik_przesuniecia_prostej() >= 0)
    {
        std::cout << "+";
    }
    std::cout << pr1.wspolczynnik_przesuniecia_prostej() << std::endl;

    std::cout << "y2 = " << pr2.wspolczynnik_kierunkowy_prostej() << "x ";
    if(pr2.wspolczynnik_przesuniecia_prostej() >= 0)
    {
        std::cout << "+";
    }
    std::cout << pr2.wspolczynnik_przesuniecia_prostej() << std::endl;

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
