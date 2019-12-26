#include "Rzecz.hpp"
#include "Osoba.hpp"
#include "Wypozyczenie.hpp"
#include "Biblioteka.hpp"

Biblioteka::Biblioteka() {}

Biblioteka::~Biblioteka() {
    for( auto i : rzeczy )
        delete i;

    for( auto i : klienci )
        delete i;

    for( auto i : wypozyczenia )
        delete i;
}

int Biblioteka::dodajRzecz( Rzecz * r ) {
    rzeczy.push_back( r );
    r->identyfikator( rzeczy.size() - 1 );
    r->dostepnosc( true );
    return r->identyfikator();
}

int Biblioteka::dodajKlienta( Klient * k ) {
    klienci.push_back( k );
    k->identyfikator( klienci.size() - 1 );
    return k->identyfikator();
}

int Biblioteka::noweWypozyczenie( int klient, int rzecz ) {
    if( rzeczy[ rzecz ]->dostepnosc() == true ) {
        rzeczy[ rzecz ]->dostepnosc( false );
        Wypozyczenie * nowe = new Wypozyczenie( klient, rzecz );
        wypozyczenia.push_back( nowe );
        nowe->identyfikator( wypozyczenia.size() - 1 );
        nowe->zwrocone( false );
        return nowe->identyfikator();
    } else {
        return -1;
    }
}

int Biblioteka::noweWypozyczenie( Klient * klient, Rzecz * rzecz ) {
    return noweWypozyczenie( klient->identyfikator(), rzecz->identyfikator() );
}

int Biblioteka::zwrotWypozyczenia( int id ) {
    if( wypozyczenia[ id ]->zwrocone() == false ) {
        rzeczy[ wypozyczenia[ id ]->rzecz() ]->dostepnosc( true );
        wypozyczenia[ id ]->zwrocone( true );
        return id;
    } else {
        return -1;
    }
}

int Biblioteka::zwrotWypozyczenia( Wypozyczenie * wypozyczenie ) {
    return zwrotWypozyczenia( wypozyczenie->identyfikator() );
}

std::vector< int > Biblioteka::wypozyczoneRzeczy() {
    std::vector< int > wypozyczone;
    for( auto i : wypozyczenia ) {
        if( i->zwrocone() == false ) {
            wypozyczone.push_back( i->identyfikator() );
        }
    }
    return wypozyczone;
}

std::vector< int > Biblioteka::wypozyczoneRzeczy( int klient ) {
    std::vector< int > wypozyczone;
    for( auto i : wypozyczenia ) {
        if( i->klient() == klient ) {
            if( i->zwrocone() == false ) {
                wypozyczone.push_back( i->identyfikator() );
            }
        }
    }
    return wypozyczone;
}

std::vector< int > Biblioteka::wypozyczoneRzeczy( Klient * klient ) {
    return wypozyczoneRzeczy( klient->identyfikator() );
}

std::vector< int > Biblioteka::historiaWypozyczen() {
    std::vector< int > wypozyczone;
    for( auto i : wypozyczenia ) {
        wypozyczone.push_back( i->identyfikator() );
    }
    return wypozyczone;
}

std::vector< int > Biblioteka::historiaWypozyczen( int klient ) {
    std::vector< int > wypozyczone;
    for( auto i : wypozyczenia ) {
        if( i->klient() == klient ) {
            wypozyczone.push_back( i->identyfikator() );
        }
    }
    return wypozyczone;
}

std::vector< int > Biblioteka::historiaWypozyczen( Klient * klient ) {
    return wypozyczoneRzeczy( klient->identyfikator() );
}

Rzecz * Biblioteka::rzecz( int id ) {
    return rzeczy[ id ];
}

Klient * Biblioteka::klient( int id ) {
    return klienci[ id ];
}

Wypozyczenie * Biblioteka::wypozyczenie( int id ) {
    return wypozyczenia[ id ];
}
