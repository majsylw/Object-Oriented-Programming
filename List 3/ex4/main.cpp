#include "Podatnik.hpp"
#include "OsobaFizyczna.hpp"
#include "Firma.hpp"
#include "Fundacja.hpp"
#include "Data.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <sstream>

/*W zesz³ym semestrze uczyliœmy siê o prostym dziedziczeniu. Zaprojektuj prost¹ hierarchiê klas, w której klasa bazowa bêdzie
reprezentowa³a podatnika, i której interfejs (wirtualna metoda) bêdzie umo¿liwia³a otrzymanie napisu z danymi podatnika.
Spróbuj zadeklarowaæ w klasie bazowej równie¿ destruktor jako wirtualny i zdefiniowaæ go z pustym cia³em funkcji
(bêdzie wyt³umaczone dlaczego).
Napisz trzy klasy pochodne, reprezentuj¹ce podatników okreœlonego rodzaju: osoby fizyczne, opisane imieniem, nazwiskiem,
dat¹ urodzenia i numerem pesel, firmy, opisane nazw¹ i numerem NIP, oraz fundacje, opisane nazw¹, numerem KRS oraz informacj¹,
czy s¹ po¿ytku publicznego, czy nie. Ka¿d¹ z klas pochodnych wyposa¿ w wersjê wirtualnej metody do generowania napisu z danymi
podatnika.

Po drugie, napisz funkcjê, która dla przekazanej referencji do strumienia wejœciowego podejmie próbê rozpoznania,
jakiej kategorii, osoby, firmy, czy fundacji dane znajduj¹ siê na pocz¹tku wejœcia, i która, po udanym wczytaniu kompletu danych,
utworzy obiekt stosownej klasy pochodnej na stercie, wskaŸnik do niego umieszczaj¹c od razu w obiekcie std::unique_ptr
przechowuj¹cym wskaŸnik do klasy bazowej, a nastêpnie ten obiekt std::unique_ptr zwróci jako swoj¹ wartoœæ.
Dane dla osoby bêd¹ siê zaczynaæ od <osoba i koñczyæ na >, podobnie dane dla firmy bêd¹ siê zaczynaæ od <firma i koñczyæ na >,
a dla fundacji zaczynaæ od <fundacja i koñczyæ na >. Mo¿na za³o¿yæ, ¿e dane s¹ poprawne i nie walczyæ o szczgó³ow¹ diagnostykê
b³êdów wejœcia.

Po trzecie, napisz funkcjê, która dla otrzymanej referencji do strumienia wejœciowego bêdzie wywo³ywaæ funkcjê z punktu trzeciego
a¿ do wyczerpania strumienia, a otrzymane obiekty std::unique_ptr bêdzie kolejno umieszczaæ w stosownym wektorze, który zwróci
na koniec jako swoj¹ wartoœæ.

Po czawarte, wywo³aj funkcjê z punktu czwartego z jakimiœ przygotowanymi danymi, a nastêpnie, dla ka¿dego podatnika w otrzymanej
kolekcji wyœwietl jego dane (ewentualnie sprawdŸ w funkcji testuj¹cej czy dane s¹ poprawnie odczytane).
*/

std::unique_ptr<Podatnik> wczytaj_podatnika(std::istream& wejscie)
{
    std::string dane;
    wejscie >> dane;

    //if (wejscie)
    //{
        if (dane ==  "<osoba") {
            std::string imie;
            std::string nazwisko;
            std::string pesel;
            int rok;
            int miesiac;
            int dzien;

            wejscie >> imie >> nazwisko >> pesel >> rok >> miesiac >> dzien;
            wejscie.get();

            //if (wejscie)
            //{
                std::unique_ptr<Podatnik> a = std::unique_ptr<Podatnik>(new OsobaFizyczna(imie, nazwisko, pesel, rok, miesiac, dzien));
                return a;
            //}
        } else if (dane =="<firma") {
            std::string nazwa;
            std::string nip;
            wejscie >> nazwa;
            wejscie >> std::ws;

            while (wejscie.peek() != '>')
            {
                nip += wejscie.get();
            }
            wejscie.get();
            //if (wejscie) {
                std::unique_ptr<Podatnik> a = std::unique_ptr<Podatnik>(new Firma(nazwa, nip));
                return a;
            //}
        }
        else //if (dana == "<fundacja")
        {
            std::string nazwa;
            std::string krs;
            bool pub;

            wejscie >> nazwa >> krs >> pub;
            wejscie.get();
            //if (wejscie) {
                std::unique_ptr<Podatnik> a = std::unique_ptr<Podatnik>(new Fundacja(nazwa, krs, pub));
                return a;
            //}
        }
    //}

    //wejscie.setstate(std::ios::failbit);
    //return std::unique_ptr<Podatnik>();
}

std::vector<std::unique_ptr<Podatnik>> wczytaj_podatnikow(std::istream& wejscie)
{
    std::vector<std::unique_ptr<Podatnik>> wsk;
    while (!wejscie.eof())
    {
        wsk.push_back(wczytaj_podatnika(wejscie));
    }
    return wsk;
}

void test_danych(void)
{
    std::istringstream strumien(
                            "<osoba Aleksandra Nawalka 98040402306 1998 4 4>\n"
                            "<osoba Marianna Walewska 42081002306 1942 8 10>\n"
                            "<firma IMAC 114-12-12-357>\n"
                            "<fundacja Polsat 40954183286 1>\n"
                            "<firma EIT+ 234-77-22-131>\n"
                            "<osoba Milena Szymczyk 94031402306 1994 3 14>\n"
                            "<firma Volvo 156-43-02-238>\n"
                            "<fundacja TVN 4280144286 1>\n"
                            "<firma Novasome 941-30-73-802>\n"
                            "<fundacja CENTAURUS 4010682286 0>\n"
                            "<osoba Jan Kotulski 98091102306 1998 11 21>\n"
                            "<firma MANUS 193-65-12-321>\n"
                        );
    std::vector<std::unique_ptr<Podatnik>> v = wczytaj_podatnikow(strumien);

    for (int i = 0; i < int(v.size() - 1); ++i)
    {
        std::cout << v[i]->Dane() << "\n";
    }
}

int main(void)
{
    test_danych();

    return 0;
}
