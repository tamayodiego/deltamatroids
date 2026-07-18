#ifndef GENERACIONDM_MGEVMODULE_H_
#define GENERACIONDM_MGEVMODULE_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <thread>
#include <utility>
#include <omp.h>
#include "Definiciones.h"
#include "Huella.h"
#include "ModuloMDDM.h"
#include "ModuloMGCP.h"
#include "DeltaMatroide.h"
#include "Modulo.h"

class ModuloMGEV : public Modulo {

private:
    ModuloMDDM valida_DeltaMatroide;
    ModuloMGCP conjunto_Pv;
  
    void AplicaExtension(std::vector<Factible>& destino ,std::vector<Factible>& origen,std::vector<bool>& ext);
    void GeneraCombinaciones( std::vector<std::vector<bool> >& comb,std::vector<bool>& auxiliar,unsigned n,unsigned ite);
    void GeneraListaBorrado();

public:
    unsigned cardV;
    void ImprimeListaBorrado(std::vector<DeltaMatroide>& lista_borrado);
    ModuloMGEV(unsigned V);
    ModuloMGEV();
   // ModuloMGEV(const ModuloMGEV& module);
    ~ModuloMGEV();
    void GeneraListaBorrado(unsigned h,DeltaMatroide& Dm,std::vector<DeltaMatroide*>& lista_borrado);
   
};

#endif // GENERACIONDM_MGEVMODULE_H_