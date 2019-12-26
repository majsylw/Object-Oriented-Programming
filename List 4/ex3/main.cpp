#include <iostream>
#include <cstdlib>

/*Na wyk�adzie poznali�my spos�b alokowania obiekt�w na stercie, ale nie poznali�my do ko�ca sposob�w radzenia sobie
z konsekwentnym zwalnianiem niepotrzebnej ju� pami�ci. W tym zadaniu tre�ci� jest napisanie b��dnego,
�le skonstruowanego programu, kt�rego jedynym efektem ma by� wyciek pami�ci, kt�ry doprowadzi na koniec do sytuacji,
w kt�rej ca�a pami�� systemowa zostanie przydzielona, i na kolejne obiekty ju� jej zabraknie. Mo�na to osi�gn�� alokuj�c
w p�tli do�� du�e obiekty, na przyk�ad zawieraj�ce atrybut tablicowy typu char duza_tablica[0x100000];
(napis 0x100000 to w uk�adzie szesnastkowym 2^20, czyli tablica ma rozmiar 1MB, mo�na eksperymentowa� z innymmi rozmiarami),
i nigdy ich nie zwalnia�. Brak pami�ci jest sygnalizowany przez system przez zg�oszenie wyj�tku typu std::bad_alloc.
Ile uda�o Ci si� zaalokowa� pami�ci dla blok�w o zadanym rozmiarze zanim pami�� si� sko�czy�a?
Uwaga: prosz� w czasie eksperyment�w pozamyka� inne programy z wa�nymi dokumentami, poniewa� system mo�e by� momentami niestabilny
lub nie odpowiada� na polecenia.*/

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
