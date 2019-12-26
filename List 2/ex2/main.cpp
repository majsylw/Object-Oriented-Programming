#include "Punkt.h"
#include "Droga.h"
#include "Prosta.h"
#include <iostream>
#include <cassert>


/*Zdefiniuj klasê Punkt reprezentuj¹c¹ punkt na p³aszczyŸnie (bêdziemy potrzebowali tylko wspó³rzêdnych kartezjañskich),
i umieœæ jej kod wraz z funkcj¹ testuj¹c¹ w stosownym komplecie plików hpp i cpp. Zdefiniuj klasê Droga reprezentuj¹c¹
drogê sk³adaj¹c¹ siê z odcinków pomiêdzy kolejnymi zadanymi punktami i potrafi¹c¹ obliczyæ swoj¹ d³ugoœæ. Umieœæ jej kod
wraz z funkcj¹ testuj¹c¹ w stosownym komplecie plików hpp i cpp. Zdefiniuj klasê Prosta reprezentuj¹c¹ prost¹ na p³aszczyŸnie.
Wyposa¿ j¹ co najmniej w konstruktor pozwalaj¹cy zadaæ dwa punkty, przez które ma ona przechodziæ, oraz w metody pozwalaj¹ce
odczytaæ wspó³czynnik kierunkowy i przesuniêcie przy interpretacji prostej jako funkcji liniowej (jakie tu s¹ szczególne przypadki?).
Umieœæ jej kod wraz z funkcj¹ testuj¹c¹ w stosownym komplecie plików hpp i cpp. Napisz aplikacjê, która przetestuje klasy,
z których korzysta i zademonstruje ich dzia³anie. Je¿eli do aplikacji potrzeba dodatkowych operacji w którejœ klasie,
mo¿esz oczywiœcie je w stosownych miejscach dopisaæ, pamiêtaj aby je równie¿ testowaæ.*/


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
