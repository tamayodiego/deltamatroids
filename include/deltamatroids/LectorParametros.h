#ifndef GENERACIONDM_PARAMETROS_H_
#define GENERACIONDM_PARAMETROS_H_

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include "Estructuras.h"


class LectorParametros {
    private:
        std::vector<std::string> params;
        int DecodificaParametro(char param[]);
        bool EsUnNumero(std::string& cadena);
    public:
        LectorParametros();
        void AnalizaParametros(int argc, char *argv[],Parametros *p);    
};

#endif