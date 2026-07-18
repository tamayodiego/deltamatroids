#ifndef GENERACIONDM_LECTOR_H_
#define GENERACIONDM_LECTOR_H_
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Definiciones.h"
#include "DeltaMatroide.h"

class LectorEntrada{
    private:

        void ConvierteAFactible(Factible& F,std::string cad);
        bool ConstruyeFamilia(std::vector<Factible>& fam, std::string& cadena);
        void ConstruyeNombre(std::string& cadDestino,std::string& cadOrigen);
    public:
        std::vector<DeltaMatroide> lista;
        bool LeerArchivoDeTexto(const char nombre_archivo[]);
};



#endif