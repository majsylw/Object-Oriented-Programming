#ifndef WypozyczenieHPP
#define WypozyczenieHPP

class Wypozyczenie {
  private:
    int id;
    int kid;
    int rid;
    bool zwrot;

  public:
    Wypozyczenie( int, int );
    ~Wypozyczenie();
    int identyfikator( int );
    int identyfikator();
    int klient();
    int rzecz();
    bool zwrocone( bool );
    bool zwrocone();
};

#endif
