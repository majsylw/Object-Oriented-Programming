#ifndef BibliotekaHPP
#define BibliotekaHPP

#include <vector>
#include "Rzecz.hpp"
#include "Klient.hpp"
#include "Wypozyczenie.hpp"

class Biblioteka {
  private:
    std::vector< Rzecz * > rzeczy;
    std::vector< Klient * > klienci;
    std::vector< Wypozyczenie * > wypozyczenia;

  public:
    Biblioteka();
    ~Biblioteka();
    int dodajRzecz( Rzecz * );
    int dodajKlienta( Klient * );
    int noweWypozyczenie( int, int );
    int noweWypozyczenie( Klient *, Rzecz * );
    int zwrotWypozyczenia( int );
    int zwrotWypozyczenia( Wypozyczenie * );
    std::vector< int > wypozyczoneRzeczy();
    std::vector< int > wypozyczoneRzeczy( int );
    std::vector< int > wypozyczoneRzeczy( Klient * );
    std::vector< int > historiaWypozyczen();
    std::vector< int > historiaWypozyczen( int );
    std::vector< int > historiaWypozyczen( Klient * );

    Rzecz * rzecz( int i );
    Klient * klient( int i );
    Wypozyczenie * wypozyczenie( int i );
};

#endif
