#ifndef GENERACIONDM_MEIMODULE_H_
#define GENERACIONDM_MEIMODULE_H_

#include <iostream>
#include <vector>
#include <string>
#include "Definiciones.h"
#include "DeltaMatroide.h"
#include "Modulo.h"
#include "Huella.h"

class ModuloMEI : public Modulo {
  private:
    bool buscaDMEnLista(DeltaMatroide& D, std::vector<DeltaMatroide*>& lista_entrada );
  
  public:
    ModuloMEI();
    void EjecutaDepuracion( std::vector<DeltaMatroide*>& lista_obstrucciones, std::vector<DeltaMatroide*>& lista_entrada);//,bool imp);
    void ImprimeListaObstrucciones(std::vector<DeltaMatroide>& lista);
    void OrdenaDeltaMatroides(std::vector<DeltaMatroide>& lista);
    bool BuscaDeltaEquivalentes(DeltaMatroide& D, unsigned i,std::vector<DeltaMatroide*>& lista);
};

#endif // GENERACIONDM_MEIMODULE_H_