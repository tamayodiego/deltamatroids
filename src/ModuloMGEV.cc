#include "ModuloMGEV.h"

void ModuloMGEV::GeneraCombinaciones(std::vector<std::vector<bool>> &comb,
                                     std::vector<bool> &auxiliar,
                                     unsigned n, unsigned ite)
{
    if (n == ite)
    {
        std::vector<bool> temp(auxiliar);
        comb.push_back(temp);
    }
    else
    {
        auxiliar[ite] = true;
        GeneraCombinaciones(comb, auxiliar, n, ite + 1);
        auxiliar[ite] = false;
        GeneraCombinaciones(comb, auxiliar, n, ite + 1);
    }
}
void ModuloMGEV::AplicaExtension(std::vector<Factible> &destino, std::vector<Factible> &origen, std::vector<bool> &ext)
{
    for (int i = 0; i < origen.size(); i++)
    {
        if (ext[i])
            destino.push_back(origen[i]); //// preguntar que esto funcione//OK
    }
}

void ModuloMGEV::ImprimeListaBorrado(std::vector<DeltaMatroide> &lista_borrado)
{
    ImprimeLista(lista_borrado);
}

void ModuloMGEV::GeneraListaBorrado(unsigned h,DeltaMatroide &Dm, std::vector<DeltaMatroide *> &lista_borrado)
{
    // generamos todos los subconjuntos
    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);
    std::vector<std::vector<bool>> combinaciones;
    std::vector<bool> comb_auxiliar(conjunto_Pv.Pv_con_Vmas.size()/2, false);
    GeneraCombinaciones(combinaciones, comb_auxiliar, conjunto_Pv.Pv_con_Vmas.size()/2, 0);
    /// probamos cuales de esas combinaciones son DeltaMatroides
    /// familia de subconjuntos temporal donde alamacenareos una extension
    #pragma omp parallel for schedule(dynamic)
    for(unsigned j=0; j<combinaciones.size(); ++j){
        std::vector<Factible> familia_temporal;
        DeltaMatroide *dm_temporal;
        std::string nombre;
        for(unsigned k=0;k<combinaciones.size(); ++k){
            std::vector<bool> ext(combinaciones[j]);
            ext.insert(ext.end(),combinaciones[k].begin(),combinaciones[k].end());
            familia_temporal.assign(Dm.familia_subconjuntos.begin(), Dm.familia_subconjuntos.end());
            AplicaExtension(familia_temporal, conjunto_Pv.Pv_con_Vmas, ext);
        //// si la etension creeada es un DM entonces se agregara a la lista de extensiones/// de borrado
            if (valida_DeltaMatroide.IsMatroide(familia_temporal) && familia_temporal.size() > Dm.familia_subconjuntos.size())
            {
                nombre = Dm.nombre +
                "-Ext" + std::to_string(lista_borrado.size() + 1);
                dm_temporal = new DeltaMatroide(nombre, familia_temporal, Dm.GetV() + 1);
                #pragma omp critical
                lista_borrado.push_back(dm_temporal);
            }

        }
    }
}
ModuloMGEV::ModuloMGEV(unsigned V) : valida_DeltaMatroide(), conjunto_Pv(V), cardV(V)
{
}
ModuloMGEV::~ModuloMGEV()
{
}
