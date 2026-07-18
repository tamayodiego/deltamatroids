#ifndef GENERACIONDM_EXPORTADOR_H_
#define GENERACIONDM_EXPORTADOR_H_
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Definiciones.h"
#include "DeltaMatroide.h"

class ExportadorSalida{
  
    public:
        
        bool EscribirArchivoDeTexto(std::vector<DeltaMatroide> lista, const char nombre_archivo[]);
};



#endif