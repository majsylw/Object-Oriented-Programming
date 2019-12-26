#include "Ryzyko.hpp"
#include "Wypadek.hpp"
#include "Pozar.hpp"
#include "SzkodaNaturalna.hpp"
#include "OC.hpp"

#include <iostream>

Ryzyko::Ryzyko(double c, int w, double u, double r, std::string m)
:cena(c), wiek(w), udzial(u), rabat(r), marka(m), polisa(0.0)
{
    assert(c > 0 && w > 0 && r >= 0 && u >= 0);
}

void Ryzyko::DodajPodryzyko(std::string nazwa)
{
    unsigned int i = 0;

    if (nazwa == "wypadek")
    {
        for(i = 0; i < typy.size(); ++i)
        {
            if(typy[i] == nazwa)
                break;
        }

        if(i == typy.size())
        {
            typy.push_back(nazwa);
            podryzyka.push_back(std::unique_ptr<Podryzyko>(new Wypadek(wiek, udzial)));
            polisa += podryzyka.back()->Skladka(cena);
        }
        else
        {
            std::cout << "Juz dodano ubezpieczenie w razie wypadku.\n";
        }
    }

    else if (nazwa == "pozar")
    {
        for(i = 0; i < typy.size(); ++i)
        {
            if(typy[i] == nazwa)
                break;
        }

        if(i == typy.size())
        {
            typy.push_back(nazwa);
            podryzyka.push_back(std::unique_ptr<Podryzyko>(new Pozar()));
            polisa += podryzyka.back()->Skladka(cena);
        }
        else
        {
            std::cout << "Juz dodano ubezpieczenie w razie pozaru.\n";
        }
    }
    else if (nazwa == "OC")
    {
        for(i = 0; i < typy.size(); ++i)
        {
            if(typy[i] == nazwa)
                break;
        }

        if(i == typy.size())
        {
            typy.push_back(nazwa);
            podryzyka.push_back(std::unique_ptr<Podryzyko> (new OC(4.18)));
            polisa += podryzyka.back()->Skladka(rabat);
        }
        else
        {
            std::cout << "Juz dodano ubezpieczenie od odpowiedzialnosci cywilnej.\n";
        }

    }
    else
    {
        for(i = 0; i < typy.size(); ++i)
        {
            if(typy[i] == nazwa)
                break;
        }

        if(i == typy.size())
        {
            typy.push_back(nazwa);
            podryzyka.push_back(std::unique_ptr<Podryzyko> (new SzkodaNaturalna()));
            polisa += podryzyka.back()->Skladka(cena);
        }
        else
        {
            std::cout << "Juz dodano ubezpieczenie w razie szkody z przyczyn naturalnych.\n";
        }
    }
}

void Ryzyko::UsunPodryzyko(std::string nazwa)
{
    unsigned int i=0;

    for(i = 0; i < typy.size(); ++i)
    {
        if(typy[i] == nazwa)
            break;
    }

    if(i == typy.size())
    {
        std::cout << "Nie dodano wczesniej podryzyka typu: " << nazwa << ".\n";
    }
    else
    {
        if(nazwa == "OC")
            polisa -= podryzyka[i]->Skladka(rabat);
        else
            polisa -= podryzyka[i]->Skladka(cena);

        podryzyka.erase(podryzyka.begin()+i);
        typy.erase(typy.begin()+i);
    }
}


double Ryzyko::WartoscPojazdu(void) const
{
    return cena;
}

int Ryzyko::WiekWlasciciela(void) const
{
    return wiek;
}

std::string Ryzyko::Marka(void) const
{
    return marka;
}

double Ryzyko::Polisa(void) const
{
    return polisa;
}

void Ryzyko::WypiszUbezpieczenia(void) const
{
    std::cout << "Wybrane ubezpieczenia:\n";
    for(unsigned int i = 0; i < typy.size(); ++i)
    {
        std::cout << typy[i] << " ";
    }
    std::cout << std::endl;
}
