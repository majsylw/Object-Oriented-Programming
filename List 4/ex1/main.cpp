#include "Data.hpp"
#include <iostream>

/*Jeszcze raz klasa Data. Wyposa� klas� Data w klasy wyj�tk�w, kt�re b�dzie zg�asza� konstruktor w razie przekazania
nieprawid�owych danych. Wiemy ju�, �e obiekt wyj�tku nie powinien zawiera� danych, kt�rych rozmiar nie jest znany
w czasie kompilacji, ale mo�e zawiera� inne dane, na przyk�ad liczby itp (warto�� liczby oczywi�cie nie jest znana,
ale je�eli przeznaczamy na ni� 32-bitowy int, to wiemy, �e potrzeba nam czterech bajt�w, i cztery jest tym znanym rozmiarem).
Wyposa� klasy wyj�tk�w w atrybuty, kt�re pozwol� odczyta�, jakie b��dne dane zosta�y przekazane konstruktorowi.
Przetestuj, czy konstruktor w�a�ciwie ustawia te atrybuty w zg�aszanych wyj�tkach. Napisz przyk�adow� aplikacj�,
kt�ra je wykorzysta.*/

int main()
{
    test_Daty();

    Data d(1999,1,1);

    std::cout << "Podaj date: (rok miesiac dzien)" << std::endl;
    std::cin >> d;
    std::cout << "Poprawnie wpisales date. Do widzenia. \n";

    return 0;
}
