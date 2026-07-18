#ifndef GENERACIONDM_MERMODULE_H_
#define GENERACIONDM_MERMODULE_H_

#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include "Modulo.h"
#include "DeltaMatroide.h"
#include "Definiciones.h"
#include "Huella.h"

class ModuloMER : public Modulo {
private:
    void GeneraVectores(unsigned i,unsigned V, std::vector<int> &vectorR,std::vector<std::vector<int>> &aux);

   

public:
   ModuloMER();
   void GeneraExtensionesTernarias(unsigned h, MatrixR& M,std::vector<DeltaMatroide>& LOut);
};

#endif // GENERACIONDM_MERMODULE_H_