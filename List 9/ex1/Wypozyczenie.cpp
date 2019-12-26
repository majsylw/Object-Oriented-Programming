#include "Wypozyczenie.hpp"

Wypozyczenie::Wypozyczenie( int k, int r ) : kid( k ), rid( r ) {}

Wypozyczenie::~Wypozyczenie() {}

int Wypozyczenie::identyfikator( int i ) {
    return id = i;
}

int Wypozyczenie::identyfikator() {
    return id;
}

int Wypozyczenie::klient() {
    return kid;
}

int Wypozyczenie::rzecz() {
    return rid;
}

bool Wypozyczenie::zwrocone( bool z ) {
    return zwrot = z;
}

bool Wypozyczenie::zwrocone() {
    return zwrot;
}
