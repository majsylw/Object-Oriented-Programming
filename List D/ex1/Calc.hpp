#include <string>
#include <sstream>
#include <functional>
#include <initializer_list>

class Calc {
  private:
    std::function< void( std::string s ) > updater;
    std::string viewer = "0";

    double poprzednia = 0;
    double biezaca = 0;
    bool przecinek = false;
    int przesuniecie = 0;
    int dzialanie = 0;
    int ostatnio = 0;
    bool wprowadzono = false;
    bool poWyliczeniu = false;

    void wyznaczPrzesuniecie();
    void uaktualnijEkran();
    void czysc(); 
    void czyscBardzo();
    void wejscie( int liczba );
    void poPrzecinku();
    void operacja( int wybor );
    void wylicz();
    void wyliczBardzo();

  public:
    enum Button { Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
                  Add, Sub, Mul, Div, Eq, Sep, CE };

    Calc() {}
    ~Calc() {}
    void Press( Button wybor );
    void Press( std::initializer_list< Button > wybory );
    void SetDisplayUpdateHandler( const std::function< void( std::string s ) > f );
};
