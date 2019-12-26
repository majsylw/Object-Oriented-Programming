#include "OC.hpp"

OC::OC(double kurs)
{
    const double k = 1000000; /*Od dnia 11 czerwca 2012r. sumy gwarancyjne wynosz¹
                                w przypadku szkód w mieniu  szkody w mieniu - 1 000 000 euro
                                w odniesieniu do jednego zdarzenia, którego skutki s¹ objête
                                ubezpieczeniem bez wzglêdu na liczbê poszkodowanych.*/
    kwota_gwarancyjna = k * kurs;//na 28.11.14r. 4,18
}

double OC::Skladka(double rabat)
{
    assert(rabat >= 0.0);

    return 0.0003*kwota_gwarancyjna*(1-rabat/100.0);
}
