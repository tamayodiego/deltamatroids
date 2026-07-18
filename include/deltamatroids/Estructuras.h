#ifndef GENERACIONDM_STRUCT_H_
#define GENERACIONDM_STRUCT_H_
#include <vector>
#include <string>
#include "DeltaMatroide.h"
#include "ModuloMGEV.h"
#include "ModuloMER.h"
#include "ModuloMEI.h"

typedef struct ListasMulti
{
    std::vector<DeltaMatroide *> lista_extensiones, lista_ternarios, lista_ternarios_depurados;
    std::vector<DeltaMatroide *> lista_no_ternarios, lista_obstrucciones;
    bool ternaiosListos, noBinariosListo;
    ListasMulti() : ternaiosListos(false), noBinariosListo(false)
    {
    }
} ListasMulti;

typedef struct Parametros
{
    unsigned hilos;
    bool modo;
    bool depuracionM;
    std::string in;
    std::string out;
} Parametros;

/*
typedef struct Modulos
{
    ModuloMGEV generador;
    ModuloMER evaluador;
    ModuloMEI depurador;
    Modulos(unsigned V) : generador(V), evaluador(V + 1)
    {
    }

} Modulos;
*/
#endif 

