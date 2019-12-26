#include "Pesel.hpp"

const char* Pesel::ZlyPesel::what(void) const noexcept { return "Podany pesel nie jest poprawny."; }

const char* Pesel::ZlaDataWPesel::what(void) const noexcept { return "Podana data w peselu jest bledna."; }

const char* Pesel::ZlaCyfraKontrolna::what() const noexcept { return "Cyfra kontrolna w podanym peselu jest niepoprawna."; }

bool przestepny(int rok)
{
    return ((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool poprawna_data(int dzien, int miesiac, int rok)
{
    if(rok > 1899)
    {
        if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12)
        {
            if (dzien > 0 && dzien < 32)
                return true;
        }
        else
        {
            if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
            {
                if(dzien > 0 && dzien < 31)
                    return true;
            }
            if (miesiac == 2)
            {
                if (przestepny(rok))
                {
                    if(dzien > 0 && dzien < 30)
                        return true;
                }
                else
                {
                    if(dzien > 0 && dzien < 29)
                        return true;
                }
            }
        }
    }

    return false;
}

bool poprawna_data_w_PESEL(std::string pesel)
{
    for(int i = 0; i < 10; ++i)
    {
        if(pesel[i] < '0' || pesel[i] > '9')
            return false;
    }

    std::string rok = pesel.substr(0,2);
    std::istringstream przypis_roku(rok);
    int rok_liczba = 0;
    przypis_roku >> rok_liczba;

    std::string miesiac = pesel.substr(2,2);

    std::string dzien = pesel.substr(4,2);
    std::istringstream strumien_dnia(dzien);
    int dzien_liczba = 0;
    strumien_dnia >> dzien_liczba;

    if(miesiac[0] == '0' || miesiac[0] == '1')
        rok_liczba += 1900;
    if(miesiac[0] == '2' || miesiac[0] == '3')
        rok_liczba += 2000;
    if(miesiac[0] == '4' || miesiac[0] == '5')
        rok_liczba += 2100;
    if(miesiac[0] == '6' || miesiac[0] == '7')
        rok_liczba += 2200;
    if(miesiac[0] == '8' || miesiac[0] == '9')
        rok_liczba += 2300;

    if(miesiac[0]%2 == 0)
        miesiac[0] = '0';
    else
        miesiac[0] = '1';

    std::istringstream strumien_miesiaca(miesiac);
    int miesiac_liczba = 0;
    strumien_miesiaca >> miesiac_liczba;

    return(poprawna_data(dzien_liczba,miesiac_liczba,rok_liczba));
}

bool poprawna_cyfra_kontrolna(std::string pesel)
{
    int suma = (pesel[0]-'0')+
               3*(pesel[1] - '0')+
               7*(pesel[2] - '0')+
               9*(pesel[3] - '0')+
               (pesel[4] - '0')+
               3*(pesel[5] - '0')+
               7*(pesel[6] - '0')+
               9*(pesel[7] - '0')+
               (pesel[8] - '0')+
               3*(pesel[9] - '0')+
               (pesel[10] - '0');
    return (suma%10 == 0);
}

Pesel::Pesel(std::string pesel)
{
    if(!poprawna_data_w_PESEL(pesel)) throw ZlaDataWPesel();
    nr_pesel = pesel;
}

Pesel::Pesel(void)
{
    nr_pesel = "";
}

std::string Pesel::Numer(void) const
{
    return nr_pesel;
}

Data Pesel::Data_ur(void)
{
    std::string rok = nr_pesel.substr(0,2);
    std::istringstream przypis_roku(rok);

    int rok_liczba = 0;
    przypis_roku >> rok_liczba;

    assert(przypis_roku);

    switch(nr_pesel[2])
    {
        case '0':
            rok_liczba += 1900;
            break;
        case '1':
            rok_liczba += 1900;
            break;
        case '2':
            rok_liczba += 2000;
            break;
        case '3':
            rok_liczba += 2000;
            break;
        case '4':
            rok_liczba += 2100;
            break;
        case '5':
            rok_liczba += 2100;
            break;
        case '6':
            rok_liczba += 2200;
            break;
        case '7':
            rok_liczba += 2200;
            break;
        case '8':
            rok_liczba += 2300;
            break;
        case '9':
            rok_liczba += 2300;
            break;
    }

    std::string miesiac = nr_pesel.substr(2,2);
    if(miesiac[0]%2 == 0)
    {
        miesiac[0] = '0';
    }
    else
    {
        miesiac[0] = '1';
    }

    std::istringstream przypis_miesiaca(miesiac);

    int miesiac_liczba = 0;
    przypis_miesiaca >> miesiac_liczba;

    assert(przypis_miesiaca);

    std::string dzien = nr_pesel.substr(4,2);
    std::istringstream przypis_dnia(dzien);

    int dzien_liczba = 0;
    przypis_dnia >> dzien_liczba;

    assert(przypis_dnia);

    Data data_urodzenia(rok_liczba,miesiac_liczba,dzien_liczba);

    return data_urodzenia;
}


bool Pesel::czy_kobieta(void)
{
    int cyfra = (nr_pesel[9] - '0')%2;

    if(cyfra == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pesel::CzyPoprawny(void)
{
    return poprawna_cyfra_kontrolna(nr_pesel);
}

std::ostream& operator<<(std::ostream& wyjscie, Pesel p)
{
    return wyjscie << "Podany nr PESEL: " << p.Numer();
}

std::istream& operator>>(std::istream& wejscie, Pesel& p)
{
    std::string pesel;

    wejscie >> pesel;

    if(wejscie)
    {
        if(pesel.size() >= 11)
        {
            pesel = pesel.substr(0,11);

            if(poprawna_data_w_PESEL(pesel))
                p = Pesel(pesel);
            else
                wejscie.setstate(std::ios_base::failbit);
        }
        else
            wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}
