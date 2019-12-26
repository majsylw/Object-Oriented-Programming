#ifndef PODRYZYKO_HPP_INCLUDED
#define PODRYZYKO_HPP_INCLUDED

class Podryzyko
{
protected:
    double procent = 0.0;

public:
    Podryzyko(double p = 0.0);
    double Procent(void) const;
    virtual ~Podryzyko(void) = default;
    virtual double Skladka(double kwota);
};

#endif // PODRYZYKO_HPP_INCLUDED
