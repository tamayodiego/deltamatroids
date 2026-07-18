#ifndef GENERACIONDM_MDDMMODULE_H_
#define GENERACIONDM_MDDMMODULE_H_

#include <iostream>
#include <vector>
#include <algorithm> 
#include "Definiciones.h"

class ModuloMDDM {
private:
    bool AxiomaSimetrico(std::vector<unsigned>& F1,  std::vector<unsigned>& F2,
                         std::vector< std::vector<unsigned> >& D);
    bool BuscaFactibleEn(std::vector<unsigned>& difEnF, std::vector< std::vector<unsigned> >& D);
public:
    ModuloMDDM();
    ~ModuloMDDM();
   bool IsMatroide(std::vector<Factible>&  D);
};

#endif // GENERACIONDM_MDDMMODULE_H_