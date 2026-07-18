#ifndef GENERACIONDM_MODULODEPURACION_H_
#define GENERACIONDM_MODULODEPURACION_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <omp.h>
#include <cctype>
#include <algorithm>
#include <fstream>
#include "Modulo.h"



class ModuloDepuracion : public Modulo {
    private:
        
    public:
        ModuloDepuracion();

        void depuracionIsomorfismo(unsigned,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide>&);
        void depuracionIsomorfismo(unsigned,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide*>&);
        void depuracionIsomorfismo(unsigned,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide*>&);
        void depuracionIsomorfismo(unsigned,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide>&);


       
        


        void depuraDeltaEquivalente(unsigned,Factible&,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide>& );
        void depuraDeltaEquivalente(unsigned,Factible&,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide>& );
        void depuraDeltaEquivalente(unsigned,Factible&,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide*>& );
        void depuraDeltaEquivalente(unsigned,Factible&,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide*>& );

        void depuraDeltaEquivalente(unsigned,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide>& );
        void depuraDeltaEquivalente(unsigned,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide>& );
        void depuraDeltaEquivalente(unsigned,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide*>& );
        void depuraDeltaEquivalente(unsigned,std::vector<DeltaMatroide*>&,std::vector<DeltaMatroide*>& );

        void depuraMenores(unsigned,std::map<Factible,std::vector<Factible>>&,std::vector<DeltaMatroide>&,std::vector<DeltaMatroide>&);

        void evaluaAnchura(unsigned hilos,unsigned anchura,std::map<Factible,std::vector<Factible>>& CP,std::vector<DeltaMatroide*>& L1,std::vector<DeltaMatroide*>& L2);
};

#endif