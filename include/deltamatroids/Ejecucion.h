#ifndef GENERACIONDM_EJECUCION_H_
#define GENERACIONDM_EJECUCION_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <omp.h>
#include "DeltaMatroide.h"
#include "ModuloDepuracion.h"
#include "ModuloOperaciones.h"
#include "ModuloMGEV.h"
#include "ModuloMER.h"
#include "ModuloMEI.h"
#include "LectorEntrada.h"
#include "Definiciones.h"

class Ejecucion {
    private:
    std::vector<DeltaMatroide> *lista_de_ternarios,lista_Obs;
    
  
    public:

        Ejecucion(std::vector<DeltaMatroide> *L1);
        void ejecuta(bool modo,bool minimaliad,DeltaMatroide& D,unsigned hilos);

};

#endif