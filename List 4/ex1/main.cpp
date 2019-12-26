#include "Data.hpp"
#include <iostream>

/*Jeszcze raz klasa Data. Wyposa¿ klasê Data w klasy wyj¹tków, które bêdzie zg³asza³ konstruktor w razie przekazania
nieprawid³owych danych. Wiemy ju¿, ¿e obiekt wyj¹tku nie powinien zawieraæ danych, których rozmiar nie jest znany
w czasie kompilacji, ale mo¿e zawieraæ inne dane, na przyk³ad liczby itp (wartoœæ liczby oczywiœcie nie jest znana,
ale je¿eli przeznaczamy na ni¹ 32-bitowy int, to wiemy, ¿e potrzeba nam czterech bajtów, i cztery jest tym znanym rozmiarem).
Wyposa¿ klasy wyj¹tków w atrybuty, które pozwol¹ odczytaæ, jakie b³êdne dane zosta³y przekazane konstruktorowi.
Przetestuj, czy konstruktor w³aœciwie ustawia te atrybuty w zg³aszanych wyj¹tkach. Napisz przyk³adow¹ aplikacjê,
która je wykorzysta.*/

int main()
{
    test_Daty();

    Data d(1999,1,1);

    std::cout << "Podaj date: (rok miesiac dzien)" << std::endl;
    std::cin >> d;
    std::cout << "Poprawnie wpisales date. Do widzenia. \n";

    return 0;
}
