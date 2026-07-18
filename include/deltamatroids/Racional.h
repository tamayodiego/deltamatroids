#ifndef RACIONAL_H_
#define RACIONAL_H_

#include <iostream>
#include <cmath>

class Racional {
    private:

    int euc(int x,int y);
    void reduce();

    public:
        int numerador,denominador;
        Racional();
        Racional(int a);
        Racional(int a,int b);
        Racional operator + (const Racional &p) const;
        Racional operator - (const Racional &p) const;
        Racional operator * (const Racional &p) const;
        Racional operator / (const Racional &p) const;
        Racional operator ^ (int p) const;
        Racional& operator += (const Racional &p);
        Racional& operator -= (const Racional &p);
        Racional& operator *= (const Racional &p);
        Racional& operator /= (const Racional &p);
        operator double () const;
        friend std::ostream& operator << (std::ostream& os,const Racional& h);
};

#endif ///// RACIONAL_H_
