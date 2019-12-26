#ifndef RzeczHPP
#define RzeczHPP

class Rzecz {
  private:
    int id;
    bool dostep;

  public:
    virtual ~Rzecz() {}
    int identyfikator( int );
    int identyfikator();
    bool dostepnosc( bool );
    bool dostepnosc();
};

#endif
