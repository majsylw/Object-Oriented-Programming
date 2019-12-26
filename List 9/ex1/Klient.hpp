#ifndef KlientHPP
#define KlientHPP

class Klient {
  private:
    int id;

  public:
    virtual ~Klient() {}
    int identyfikator( int );
    int identyfikator();
};

#endif
