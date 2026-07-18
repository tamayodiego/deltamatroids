#ifndef GENERACIONDM_MMODULE_H_
#define GENERACIONDM_MMODULE_H_

#include <iostream>
#include <vector>
#include <algorithm> 
#include "Definiciones.h"
#include "DeltaMatroide.h"
#include "Huella.h"

class Modulo {
protected:
    bool HuellaEnLista(Huella& h,std::vector<Huella> lista);
    void obtenBloquesHuellas(std::vector<Huella>& lista,
                                std::vector<DeltaMatroide>& lista_borrado);
    void obtenBloquesHuellas(std::vector<Huella>& lista,
                                std::vector<DeltaMatroide*>& lista_borrado);
    
public:

    void ImprimeLista(std::vector<DeltaMatroide>& lista);
    void ImprimeLista(std::vector<DeltaMatroide*>& lista);
    Modulo();

    bool BuscaIsomorfos(std::vector<DeltaMatroide>& lista,DeltaMatroide& D);
    bool BuscaIsomorfos(std::vector<DeltaMatroide*>& lista,DeltaMatroide& D);
    bool BuscaDeltaEquivalentes(std::vector<DeltaMatroide>& lista,DeltaMatroide& D);
    bool BuscaDeltaEquivalentes(std::vector<DeltaMatroide*>& lista,DeltaMatroide& D);
};

#endif // GENERACIONDM_MDDMMODULE_H_