#ifndef GENERACIONDM_DETERMINANTE_H_
#define GENERACIONDM_DETERMINANTE_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <stack> 
#include "Definiciones.h"


class Determinante {
   // private: std::vector<unsigned> huella;
   private:
       void Diagonaliza(MatrixR& M);
       void Intercambio(unsigned i,unsigned j,MatrixR& M);
       void ConstantePorRenglon(Racional C,unsigned i,MatrixR& M);
       void SumaDeRenglones(Racional C,unsigned Ri,unsigned Rj,MatrixR& M);
      
       std::stack<Racional> pila;
      
    public:
        Determinante();
        Determinante(const Determinante& D);
        int CalculaD(MatrixR M);
      //  bool equals(Huella& h);
      //  void toString();
};

#endif // GENERACIONDM_HUELLA_H_