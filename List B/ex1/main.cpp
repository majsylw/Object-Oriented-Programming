#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <cassert>

enum Month {January=1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
            };

std::ostream& operator<<(std::ostream& wyjscie, Month miesiac)
{
    switch( miesiac ) {
        case January:
            wyjscie << "January";
            break;
        case February:
            wyjscie << "February";
            break;
        case March:
            wyjscie << "March";
            break;
        case April:
            wyjscie << "April";
            break;
        case May:
            wyjscie << "May";
            break;
        case June:
            wyjscie << "June";
            break;
        case July:
            wyjscie << "July";
            break;
        case August:
            wyjscie << "August";
            break;
        case September:
            wyjscie << "September";
            break;
        case October:
            wyjscie << "October";
            break;
        case November:
            wyjscie << "November";
            break;
        case December:
            wyjscie << "December";
            break;
        default:
            wyjscie.setstate( std::ios::failbit );
    }

    return wyjscie;
}

std::istream& operator>>(std::istream& wejscie, Month& miesiac)
{
    std::string mieszek;
    wejscie >> mieszek;
    if( wejscie ) {
        if( mieszek == "January" )
            miesiac = January;
        else if( mieszek == "February" )
            miesiac = static_cast<Month>(2);
        else if( mieszek == "March" )
            miesiac = March;
        else if( mieszek == "April" )
            miesiac = April;
        else if( mieszek == "May" )
            miesiac = May;
        else if( mieszek == "June" )
            miesiac = June;
        else if( mieszek == "July" )
            miesiac = July;
        else if( mieszek == "August" )
            miesiac = August;
        else if( mieszek == "September" )
            miesiac = September;
        else if( mieszek == "October" )
            miesiac = October;
        else if( mieszek == "November" )
            miesiac = November;
        else if( mieszek == "December" )
            miesiac = December;
        else
            wejscie.setstate( std::ios::failbit );
    }
    return wejscie;
}

template<typename F>
void ForEachMonth(F f) {
    for(int i = 1; i <= 12; ++i) {
        f( static_cast<Month>(i) );
    }
}

template<typename F>
void ForEachMonthReverse(F f) {
    for(int i = 12; i >= 1; --i) {
        f( static_cast<Month>(i) );
    }
}

auto testMonth(void) -> void
{
    std::ostringstream out;
    ForEachMonthReverse([&](Month m)
        {
        out << m << "\n";
        });
    std::istringstream in(out.str());
    std::vector<Month> v;
    std::copy(std::istream_iterator<Month>(in),std::istream_iterator<Month>(),std::back_inserter(v));
    assert(v.size()==12);
    int i=12;
    ForEachMonth([&v,&i](Month m)
        {
        assert(m == v[--i]);
        });

    std::cerr << "Testy przebiegly pomyslnie!\n";
}

int main(void)
{
    testMonth();

    return 0;
}
