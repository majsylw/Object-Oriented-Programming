#include <iostream>
#include <cstdlib>

/*Na wyk³adzie poznaliœmy sposób alokowania obiektów na stercie, ale nie poznaliœmy do koñca sposobów radzenia sobie
z konsekwentnym zwalnianiem niepotrzebnej ju¿ pamiêci. W tym zadaniu treœci¹ jest napisanie b³êdnego,
Ÿle skonstruowanego programu, którego jedynym efektem ma byæ wyciek pamiêci, który doprowadzi na koniec do sytuacji,
w której ca³a pamiêæ systemowa zostanie przydzielona, i na kolejne obiekty ju¿ jej zabraknie. Mo¿na to osi¹gn¹æ alokuj¹c
w pêtli doœæ du¿e obiekty, na przyk³ad zawieraj¹ce atrybut tablicowy typu char duza_tablica[0x100000];
(napis 0x100000 to w uk³adzie szesnastkowym 2^20, czyli tablica ma rozmiar 1MB, mo¿na eksperymentowaæ z innymmi rozmiarami),
i nigdy ich nie zwalniaæ. Brak pamiêci jest sygnalizowany przez system przez zg³oszenie wyj¹tku typu std::bad_alloc.
Ile uda³o Ci siê zaalokowaæ pamiêci dla bloków o zadanym rozmiarze zanim pamiêæ siê skoñczy³a?
Uwaga: proszê w czasie eksperymentów pozamykaæ inne programy z wa¿nymi dokumentami, poniewa¿ system mo¿e byæ momentami niestabilny
lub nie odpowiadaæ na polecenia.*/

int main(void)
{
    for(int i = 0; i < 2000; ++i)
    {
        char* duza_tablica = new char[0x100000];
        std::cout << " --> " << i << std::endl;

    }

    /*for(int i = 0; i < 2000; ++i)
    {
        try {char* duza_tablica = new char[0x100000];
        std::cout << " --> " << i << std::endl;}
        catch (std::bad_alloc& e)
        {
        std::cout << "Blad alokacji: " << e.what() << std::endl;
        }
    }*/

    return 0;
}
