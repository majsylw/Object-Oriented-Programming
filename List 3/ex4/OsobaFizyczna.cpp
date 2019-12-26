#include "OsobaFizyczna.hpp"

#include<sstream>


std::string to_string(int a)
{
  std::stringstream ss;
  ss << a;
  return ss.str();
}

OsobaFizyczna::OsobaFizyczna(std::string i, std::string n, std::string p,int r,int m,int d)
: imie(i), nazwisko(n), pesel(p), data_urodzenia(Data(r, m, d))
{ }

std::string OsobaFizyczna::Dane(void)
{
    std::string napis = "<osoba ";
    napis += imie + " " + nazwisko + " "  + pesel.Numer() + " ";
    napis += to_string( data_urodzenia.podaj_rok() );
    napis += " ";
    napis += to_string(data_urodzenia.podaj_miesiac()) + ' ' + to_string(data_urodzenia.podaj_dzien()) + ">";
    return napis;
}
