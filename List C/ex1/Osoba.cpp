#include "Osoba.hpp"

#include<sstream>

const char* Osoba::BrakSpojnosci::what(void) const noexcept { return "Podane dane nie sa wzajemnie spojne."; }

const char* Osoba::NiespojnaData::what(void) const noexcept { return "Podana data urodzenia niezgodna z data wpisana w pesel."; }

const char* Osoba::NiespojnaPlec::what() const noexcept { return "Podana plec niezgodna z peselem."; }

std::string to_string(int a)
{
  std::stringstream ss;
  ss << a;
  return ss.str();
}

Osoba::Osoba(std::string i, std::string n, std::string p, char pl, int r,int m,int d)
: imie(i), nazwisko(n), plec(pl), pesel(p), data_urodzenia(Data(r, m, d))
{
    if (pesel.czy_kobieta() != plec.czy_kobieta()) throw NiespojnaPlec();
    if (data_urodzenia != pesel.Data_ur()) throw NiespojnaData();
}

std::string Osoba::Dane(void)
{
    std::string napis = "<osoba ";
    napis += imie + " " + nazwisko + " "  + pesel.Numer() + " ";
    napis += to_string(data_urodzenia.podaj_rok());
    napis += " ";
    napis += to_string(data_urodzenia.podaj_miesiac()) + ' ' + to_string(data_urodzenia.podaj_dzien()) + ">";
    return napis;
}
