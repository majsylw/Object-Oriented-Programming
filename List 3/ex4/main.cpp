#include "Podatnik.hpp"
#include "OsobaFizyczna.hpp"
#include "Firma.hpp"
#include "Fundacja.hpp"
#include "Data.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <sstream>

/*W zesz�ym semestrze uczyli�my si� o prostym dziedziczeniu. Zaprojektuj prost� hierarchi� klas, w kt�rej klasa bazowa b�dzie
reprezentowa�a podatnika, i kt�rej interfejs (wirtualna metoda) b�dzie umo�liwia�a otrzymanie napisu z danymi podatnika.
Spr�buj zadeklarowa� w klasie bazowej r�wnie� destruktor jako wirtualny i zdefiniowa� go z pustym cia�em funkcji
(b�dzie wyt�umaczone dlaczego).
Napisz trzy klasy pochodne, reprezentuj�ce podatnik�w okre�lonego rodzaju: osoby fizyczne, opisane imieniem, nazwiskiem,
dat� urodzenia i numerem pesel, firmy, opisane nazw� i numerem NIP, oraz fundacje, opisane nazw�, numerem KRS oraz informacj�,
czy s� po�ytku publicznego, czy nie. Ka�d� z klas pochodnych wyposa� w wersj� wirtualnej metody do generowania napisu z danymi
podatnika.

Po drugie, napisz funkcj�, kt�ra dla przekazanej referencji do strumienia wej�ciowego podejmie pr�b� rozpoznania,
jakiej kategorii, osoby, firmy, czy fundacji dane znajduj� si� na pocz�tku wej�cia, i kt�ra, po udanym wczytaniu kompletu danych,
utworzy obiekt stosownej klasy pochodnej na stercie, wska�nik do niego umieszczaj�c od razu w obiekcie std::unique_ptr
przechowuj�cym wska�nik do klasy bazowej, a nast�pnie ten obiekt std::unique_ptr zwr�ci jako swoj� warto��.
Dane dla osoby b�d� si� zaczyna� od <osoba i ko�czy� na >, podobnie dane dla firmy b�d� si� zaczyna� od <firma i ko�czy� na >,
a dla fundacji zaczyna� od <fundacja i ko�czy� na >. Mo�na za�o�y�, �e dane s� poprawne i nie walczy� o szczg�ow� diagnostyk�
b��d�w wej�cia.

Po trzecie, napisz funkcj�, kt�ra dla otrzymanej referencji do strumienia wej�ciowego b�dzie wywo�ywa� funkcj� z punktu trzeciego
a� do wyczerpania strumienia, a otrzymane obiekty std::unique_ptr b�dzie kolejno umieszcza� w stosownym wektorze, kt�ry zwr�ci
na koniec jako swoj� warto��.

Po czawarte, wywo�aj funkcj� z punktu czwartego z jakimi� przygotowanymi danymi, a nast�pnie, dla ka�dego podatnika w otrzymanej
kolekcji wy�wietl jego dane (ewentualnie sprawd� w funkcji testuj�cej czy dane s� poprawnie odczytane).
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
