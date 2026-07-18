#ifndef GENERACIONDM_MGCPMODULE_H_
#define GENERACIONDM_MGCPMODULE_H_

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "Definiciones.h"
#include "Huella.h"

class ModuloMGCP {
private:
    unsigned this_V;
    
    void construye(std::vector<bool>& arr, unsigned ite,unsigned n );
    void ClasificaConjuntoPotencia();
   
public:
    std::vector<Factible> Pv_con_Vmas;
    std::vector<Factible> Pv_sin_Vmas;
    std::vector<Factible> Pv;
    ModuloMGCP(unsigned V);
    ~ModuloMGCP();
  //  std::vector<Factible>& GetPv();
  
};

#endif // GENERACIONDM_MGCPMODULE_H_