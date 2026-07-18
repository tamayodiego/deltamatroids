#include "Racional.h"

int Racional::euc(int x,int y){
  return (!y) ? x : euc(y,x%y);
}

 Racional::Racional() : numerador(0), denominador(1) {

 }

 Racional::Racional(int a) {
    denominador=1;
    numerador=a;
 }

Racional::Racional(int a,int b){
    denominador=b;
    numerador=a;
    reduce();
}

void Racional::reduce(){
    int max=euc(numerador,denominador);
    numerador=numerador/max;
    denominador=denominador/max;
}

Racional Racional::operator + (const Racional &p) const {
    Racional temp = *this;
    temp += p;
    return temp;
}

Racional Racional::operator - (const Racional &p) const {
    Racional temp = *this;
    temp -= p;
    return temp;
}

Racional Racional::operator * (const Racional &p) const {
    Racional temp = *this;
    temp *= p;
    return temp;
}

Racional Racional::operator / (const Racional &p) const {
    Racional temp = *this;
    temp /= p;
    return temp;
}

Racional Racional::operator ^ (int p) const {
     Racional temp = *this;
     if(p < 0){
        int aux=temp.numerador;
        temp.numerador=temp.denominador;
        temp.denominador=aux;
        p=p*-1;
     }
     // Potencia entera exacta (equivalente a pow para estos exponentes, sin el
     // redondeo de punto flotante que podia truncar al asignar a int).
     int num=1, den=1;
     for(int k=0;k<p;++k){
        num*=temp.numerador;
        den*=temp.denominador;
     }
     temp.numerador=num;
     temp.denominador=den;
     return temp;

}

Racional& Racional::operator += (const Racional &p){
    numerador= numerador*p.denominador + denominador*p.numerador;
    denominador=denominador*p.denominador;
    reduce();
    return *this;

}

Racional& Racional::operator -= (const Racional &p){
    numerador= numerador*p.denominador - denominador*p.numerador;
    denominador=denominador*p.denominador;
    reduce();
    return *this;

}

Racional& Racional::operator *= (const Racional &p){
    numerador*=p.numerador;
    denominador*=p.denominador;
    reduce();
    return *this;
}

Racional& Racional::operator /= (const Racional &p){
    numerador*=p.denominador;
    denominador*=p.numerador;
    reduce();
    return *this;
}

Racional::operator double () const {
    return (double) numerador / denominador;
}

std::ostream& operator << (std::ostream& os,const Racional& h){

    os << (double) h.numerador / h.denominador;

    return os;

}
