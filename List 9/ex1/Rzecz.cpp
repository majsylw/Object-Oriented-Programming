#include "Rzecz.hpp"

int Rzecz::identyfikator( int i ) {
    return id = i;
}

int Rzecz::identyfikator() {
    return id;
}

bool Rzecz::dostepnosc( bool d ) {
    return dostep = d;
}

bool Rzecz::dostepnosc() {
    return dostep;
}
