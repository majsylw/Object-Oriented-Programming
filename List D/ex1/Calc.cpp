#include "Calc.hpp"

void Calc::wyznaczPrzesuniecie() {
    int biezacai = 0;
    double biezacaf = biezaca;

    for( przesuniecie = 0; przesuniecie < 10; ++przesuniecie ) {
        biezacai = biezacaf;
        if( (biezacaf - biezacai) == 0.0 )
            break;
        biezacaf *= 10;
    }
}

void Calc::uaktualnijEkran() {
    std::ostringstream strs;
    strs << biezaca;
    std::string str = strs.str();

    if( przecinek == true ) {
        if( str.find( "." ) == std::string::npos ) {
            str.append( "." );
        }
    }

    if( viewer != str ) {
        viewer = str;
        updater( viewer );
    }
}

void Calc::czysc() {
    if( biezaca == 0 )
        poprzednia = 0;
    else
        biezaca = 0;
    przesuniecie = 0;
    przecinek = false;
    wprowadzono = false;
    poWyliczeniu = false;
    viewer = "0";
}

void Calc::czyscBardzo() {
    czysc();
    dzialanie = 0;
    ostatnio = 0;
    uaktualnijEkran();
}

void Calc::wejscie( int liczba ) {
    if( poWyliczeniu == true )
        czyscBardzo();

    if( ! przecinek ) {
        biezaca *= 10;
        biezaca += liczba;
    } else {
        double dolicz = liczba;
        ++przesuniecie;
        for( int i = 0; i < przesuniecie; ++i ) {
            dolicz /= 10;
        }
        biezaca += dolicz;
    }

    wprowadzono = true;
    uaktualnijEkran();
}

void Calc::poPrzecinku() {
    przecinek = true;
    uaktualnijEkran();
}

void Calc::operacja( int wybor ) {
    if( wprowadzono == true ) {
        if( dzialanie != 0 ) {
            wylicz();
        }

        poprzednia = biezaca;
        czysc();
    }
    dzialanie = wybor;
}

void Calc::wylicz() {
    if( dzialanie == Add ) {
        poprzednia += biezaca;
    } else if( dzialanie == Sub ) {
        poprzednia -= biezaca;
    } else if( dzialanie == Mul ) {
        poprzednia *= biezaca;
    } else if( dzialanie == Div ) {
        poprzednia /= biezaca;

        if( biezaca == 0 ) {
            poprzednia = 0;
        }
    }

    std::swap( poprzednia, biezaca );
    wyznaczPrzesuniecie();
    uaktualnijEkran();
}

void Calc::wyliczBardzo() {
    if( dzialanie == 0 ) {
        dzialanie = ostatnio;
        std::swap( poprzednia, biezaca );
    } else {
        ostatnio = dzialanie;
    }
    przecinek = false;

    wylicz();

    poWyliczeniu = true;
    dzialanie = 0;
}

void Calc::Press( Button wybor ) {
    switch( wybor ) {
        case Zero:
        case One:
        case Two:
        case Three:
        case Four:
        case Five:
        case Six:
        case Seven:
        case Eight:
        case Nine:
            wejscie( static_cast< int >( wybor ) );
            break;

        case Add:
        case Sub:
        case Mul:
        case Div:
            operacja( static_cast< int >( wybor ) );
            break;

        case Eq:
            wyliczBardzo();
            break;

        case Sep:
            poPrzecinku();
            break;

        case CE:
            czyscBardzo();
            break;

        default:
            //std::cerr << "Nieznany klawisz!" << std::endl;
            break;
    }
}

void Calc::Press( std::initializer_list< Button > wybory ) {
    for( auto wybor : wybory ) {
        Press( wybor );
    }
}

void Calc::SetDisplayUpdateHandler( const std::function< void( std::string s ) > f ) {
    updater = f;
}
