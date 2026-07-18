#ifndef GENERACIONDM_MODULOOPERACIONES_H_
#define GENERACIONDM_MODULOOPERACIONES_H_

#include <vector>
#include <map>
#include <omp.h>
#include "Modulo.h"
#include "DeltaMatroide.h"
#include "Huella.h"
#include "Definiciones.h"

class ModuloOperaciones : public Modulo{


    private:
    public:

    /// parametro p: 'a'=directo 'b'=isomorfico 'c'=deltaequivalente
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide*>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide*>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide*>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide>& LR );
    void listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide*>& LR );

    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::map<Huella,std::vector<DeltaMatroide>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::map<Huella,std::vector<DeltaMatroide*>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::map<Huella,std::vector<DeltaMatroide>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::map<Huella,std::vector<DeltaMatroide*>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::map<Huella,std::vector<DeltaMatroide>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::map<Huella,std::vector<DeltaMatroide*>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::map<Huella,std::vector<DeltaMatroide>>& LR );
    void listaAmenosBClasificadoH(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::map<Huella,std::vector<DeltaMatroide*>>& LR );

    void deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB);
    void deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB);
    void deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB);
    void deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB);

    void binarySerchDeltaMatroide(std::vector<DeltaMatroide>& L,DeltaMatroide& D);
    void binarySerchDeltaMatroide(std::vector<DeltaMatroide*>& L,DeltaMatroide& D);

   // void quitarElementosEnListaSegunAnchura(unsigned )

};

#endif